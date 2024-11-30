#ifndef DOOR_H
#define DOOR_H

#include "RenderableObject.h"

class Door : public RenderableObject {
protected:
    glm::vec3 position;
    glm::vec3 rotationAxis;
    float angle = 0.0f;

public:
    Door(ppgso::Shader& program, const std::string& modelPath, glm::vec3 position, glm::vec3 rotationAxis);
    void setAngle(float angle);
    void render() override;
};

#endif // DOOR_H
