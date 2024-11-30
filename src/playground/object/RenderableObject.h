#ifndef RENDERABLE_OBJECT_H
#define RENDERABLE_OBJECT_H

#include <ppgso/ppgso.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class RenderableObject {
protected:
    ppgso::Shader& program;
    ppgso::Texture texture;
    ppgso::Mesh mesh;
    glm::mat4 modelMatrix;

public:
    RenderableObject(ppgso::Shader& program, const std::string& texturePath, const std::string& meshPath);
    virtual void render();
};

#endif // RENDERABLE_OBJECT_H
