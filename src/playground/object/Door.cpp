#include "Door.h"

Door::Door(ppgso::Shader& program, const std::string& modelPath, glm::vec3 position, glm::vec3 rotationAxis)
    : RenderableObject(program, "china.bmp", modelPath), position(position), rotationAxis(rotationAxis) {}

void Door::setAngle(float angle) {
    this->angle = angle;
    modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(angle), rotationAxis);
}

void Door::render() {
    RenderableObject::render();
}
