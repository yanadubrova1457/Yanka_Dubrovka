#ifndef GROUND_H
#define GROUND_H

#include "RenderableObject.h"

class Ground : public RenderableObject {
public:
    Ground(ppgso::Shader& program);
    void render() override;
};

#endif // GROUND_H
