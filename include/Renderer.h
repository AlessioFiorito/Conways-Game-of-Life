#ifndef RENDERER_H
#define RENDERER_H

#include <Grid.h>


class Renderer {
public:
    Renderer(unsigned int width, unsigned int height, float cellSize);

    void render(const Grid& grid) const;

private:
    unsigned int m_windowWidth;
    unsigned int m_windowHeight;
    float m_cellSize;



};



#endif //RENDERER_H
