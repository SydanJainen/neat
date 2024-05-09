#pragma once

#include <vector>

enum class Action{
    DoNothing,
    Rotateleft,
    RotateRight,
};

enum class OrganismState{
    Alive,
    Death,
    Winner,
};

struct Coordinates{
    int x;
    int y;
};

struct Organism{
    Coordinates position;
    Action action;
};

enum class Direction{
    Up,
    Down,
    Left,
    Right,
};

class OrganismEngine{
    public:
        OrganismState process(Action action){
            current_direction = update_direction(current_direction, action);
            Coordinates new_position = update_position(position, current_direction);

            if( hits_wall(new_position) && !allow_through_walls){
                game_result = OrganismState::Death;
            }

            if (hits_food(new_position)){
                score++;
            
            }

        }
    private:
        Organism organism;
        OrganismState game_result;
        Coordinates position;
        std::vector<Coordinates> foods;
        bool allow_through_walls;
        int score;
        int width;
        int height;
        Direction current_direction;

        bool hits_wall(Coordinates position){
            return position.x < 0 || position.x >= width || position.y < 0 || position.y >= height;
        }

        bool hits_food(Coordinates position){
            return std::find(foods.begin(), foods.end(), position) != foods.end();
        }

        Direction update_direction(Direction current_direction, Action action){
            switch(action){
                case Action::DoNothing:
                    return current_direction;
                case Action::Rotateleft:
                    switch(current_direction){
                        case Direction::Up:
                            return Direction::Left;
                        case Direction::Down:
                            return Direction::Right;
                        case Direction::Left:
                            return Direction::Down;
                        case Direction::Right:
                            return Direction::Up;
                    }
                case Action::RotateRight:
                    switch(current_direction){
                        case Direction::Up:
                            return Direction::Right;
                        case Direction::Down:
                            return Direction::Left;
                        case Direction::Left:
                            return Direction::Up;
                        case Direction::Right:
                            return Direction::Down;
                    }
            }
        }

        Coordinates update_position(Coordinates position, Direction direction){
            switch(direction){
                case Direction::Up:
                    return {position.x, position.y - 1};
                case Direction::Down:
                    return {position.x, position.y + 1};
                case Direction::Left:
                    return {position.x - 1, position.y};
                case Direction::Right:
                    return {position.x + 1, position.y};
            }
        }
};

class GameEngine{
    public:
        void run(){
            OrganismEngine organism_engine;
            while(true){
                auto action = get_action();
                auto game_result = organism_engine.process(action);
                if(game_result == OrganismState::Death){
                    break;
                }
            }
        }
    private:
        Action get_action(){
            // get action from user input
        }
};