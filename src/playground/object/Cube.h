#ifndef CUBE_H
#define CUBE_H

#include "RenderableObject.h"

class Cube : public RenderableObject {
public:
    Cube(ppgso::Shader& program);
    void render() override;
};

#endif // CUBE_H
