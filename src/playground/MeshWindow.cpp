#include "MeshWindow.h"

MeshWindow::MeshWindow(int width, int height)
    : Window{"gl6_mesh", width, height},
      program(texture_vert_glsl, texture_frag_glsl),
      cube(program),
      ground(program),
      doorL(program, "doorL.obj", glm::vec3(-0.075f, 0.01f, 0.09f), glm::vec3(0.0f, 1.0f, 0.0f)),
      doorR(program, "doorR.obj", glm::vec3(0.1f, 0.01f, 0.09f), glm::vec3(0.0f, 1.0f, 0.0f)) {

  hideCursor();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
  glDisable(GL_CULL_FACE);
}

void MeshWindow::onKey(int key, int scanCode, int action, int mods) {
  if (key == GLFW_KEY_O && action == GLFW_PRESS) openDoors = !openDoors;
  if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) animationEnabled = !animationEnabled;

  if (action == GLFW_PRESS || action == GLFW_REPEAT) {
    glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPosition);
    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraUp, cameraDirection));

    if (key == GLFW_KEY_W) cameraPosition += cameraSpeed * cameraDirection;
    if (key == GLFW_KEY_S) cameraPosition -= cameraSpeed * cameraDirection;
    if (key == GLFW_KEY_A) cameraPosition -= glm::normalize(glm::cross(cameraDirection, cameraUp)) * cameraSpeed;
    if (key == GLFW_KEY_D) cameraPosition += glm::normalize(glm::cross(cameraDirection, cameraUp)) * cameraSpeed;
  }
}

void MeshWindow::onCursorPos(double cursorX, double cursorY) {
  if (firstMouse) {
    lastX = cursorX;
    lastY = cursorY;
    firstMouse = false;
  }

  float xoffset = cursorX - lastX;
  float yoffset = lastY - cursorY;
  lastX = cursorX;
  lastY = cursorY;

  xoffset *= sensitivity;
  yoffset *= sensitivity;

  yaw += xoffset;
  pitch += yoffset;

  if (pitch > 89.0f) pitch = 89.0f;
  if (pitch < -89.0f) pitch = -89.0f;

  glm::vec3 front;
  front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
  front.y = sin(glm::radians(pitch));
  front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
  cameraTarget = cameraPosition + glm::normalize(front);
}

void MeshWindow::onIdle() {
  glClearColor(.5f, .5f, .5f, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  auto viewMatrix = glm::lookAt(cameraPosition, cameraTarget, cameraUp);
  program.setUniform("ViewMatrix", viewMatrix);
  program.setUniform("ProjectionMatrix", glm::perspective(glm::radians(60.0f), (float)width / (float)height, 0.1f, 10.0f));

  static auto lastTime = glfwGetTime();
  float deltaTime = glfwGetTime() - lastTime;
  lastTime = glfwGetTime();

  if (openDoors && doorAngle < 90.0f) {
    doorAngle += doorSpeed * deltaTime;
    if (doorAngle > 90.0f) doorAngle = 90.0f;
  } else if (!openDoors && doorAngle > 0.0f) {
    doorAngle -= doorSpeed * deltaTime;
    if (doorAngle < 0.0f) doorAngle = 0.0f;
  }

  cube.render();
  ground.render();

  doorL.setAngle(doorAngle);
  doorL.render();

  doorR.setAngle(-doorAngle);
  doorR.render();
}
