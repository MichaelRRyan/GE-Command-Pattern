#ifndef BRICK_H
#define BRICK_H

class Brick
{
public:
    Brick() { }
    virtual ~Brick() { }
    virtual void render() = 0;
};

#endif // !BRICK_H