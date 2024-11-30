#include "Cube.h"

Cube::Cube(ppgso::Shader& program)
    : RenderableObject(program, "china.bmp", "res3.obj") {
    modelMatrix = glm::mat4(1.0f);
}

void Cube::render() {
    RenderableObject::render();
}
