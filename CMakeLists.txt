cmake_minimum_required(VERSION 3.25)
project(gameAI)

set(CMAKE_CXX_STANDARD 11)

add_executable(gameAI main.cpp Card/Card.h Situation/Situation.h Situation/Player.h Strategy/Strategy.h Control/Control.h Strategy/Random_strategy/Random_strategy.h Strategy/User_strategy/User_strategy.h)
