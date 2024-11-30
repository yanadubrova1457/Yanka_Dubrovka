#include "RenderableObject.h"

RenderableObject::RenderableObject(ppgso::Shader& program, const std::string& texturePath, const std::string& meshPath)
    : program(program), texture(ppgso::image::loadBMP(texturePath)), mesh(meshPath), modelMatrix(glm::mat4(1.0f)) {}

void RenderableObject::render() {
    program.setUniform("ModelMatrix", modelMatrix);
    program.setUniform("Texture", texture);
    mesh.render();
}
