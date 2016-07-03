#pragma once

#include "Map.h"
#include <list>

class Snake {
public:
    enum MoveDirection {
        NONE,
        LEFT,
        UP,
        RIGHT,
        DOWN 
    };

    Snake() = delete;
    Snake(Map *m);
    ~Snake();

    /*
    Forbid copy
    */
    Snake(const Snake &m) = delete;
    Snake& operator=(const Snake &m) = delete;

    /*
    Move at current diection.
    */
    void move();

    /*
    Check whether the snake is dead.
    */
    bool isDead() const;

    /*
    Set move direction.
    */
    void setMoveDirection(const MoveDirection &d);

    /*
    Return move direction.
    */
    MoveDirection getMoveDirection() const;

private:
    bool dead = false;

    Map *map = nullptr;  // The map that the snake attaches to

    MoveDirection direc = NONE;  // Current snake move direcition

    std::list<Point> body;

    /*
    Add a new body.

    @param p the point of the new body
    @return true if adding succeed, false otherwise
    */
    bool addBody(const Point &p);

    /*
    Remove the tail of the snake.
    */
    void removeTail();

    /*
    Get a displacement of a direction.

    @param d the move direction
    @return the displacement stored in a Point object
    */
    static Point getDisplacement(const MoveDirection &d);

    /*
    Return the head position.
    */
    const Point& getHeadPos() const;

    /*
    Return the tail position.
    */
    const Point& getTailPos() const;
};
