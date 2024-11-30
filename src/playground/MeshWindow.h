#ifndef MESH_WINDOW_H
#define MESH_WINDOW_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <ppgso/ppgso.h>
#include "object/Cube.h"
#include "object/Ground.h"
#include "object/Door.h"
#include <shaders/texture_vert_glsl.h>
#include <shaders/texture_frag_glsl.h>

class MeshWindow : public ppgso::Window {
private:
  ppgso::Shader program;

  Cube cube;
  Ground ground;
  Door doorL;
  Door doorR;

  bool animationEnabled = true;
  float time = 0.0f;

  glm::vec3 cameraPosition = {0.0f, -0.1f, 0.9f};
  glm::vec3 cameraTarget = {0.0f, 0.0f, 0.0f};
  glm::vec3 cameraUp = {0.0f, 1.0f, 0.0f};
  float yaw = -90.0f;
  float pitch = 0.0f;
  float lastX, lastY;
  bool firstMouse = true;
  float sensitivity = 0.2f;
  float cameraSpeed = 0.05f;

  bool openDoors = false;
  float doorAngle = 0.0f;
  float doorSpeed = 90.0f;

public:
  MeshWindow(int width, int height);

  void onKey(int key, int scanCode, int action, int mods) override;
  void onCursorPos(double cursorX, double cursorY) override;
  void onIdle() override;
};

#endif // MESH_WINDOW_H
