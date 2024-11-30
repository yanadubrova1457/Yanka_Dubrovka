#include "Ground.h"

Ground::Ground(ppgso::Shader& program)
    : RenderableObject(program, "ground.bmp", "quad.obj") {
    modelMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(0.0f, 0.0f, -0.3f));
}

void Ground::render() {
    RenderableObject::render();
}
