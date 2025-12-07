#pragma once

class myBlocks{
protected:
    myBlocks();
public:
    virtual void Rotate()=0;
    virtual bool CheckCollision()=0;
    virtual void MoveDown()=0;
    virtual void Delete()=0;
    virtual ~myBlocks();
};

class shapeL:public myBlocks{
public:
    void Rotate() override;
};
