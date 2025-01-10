cmake_minimum_required(VERSION 3.28)
project(GameProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameProject main.cpp
        Card.h
        StandardCard.h
        BonusCard.h
        Deck.h
        PenaltyCard.h
        Player.h
        Game.h
        Card.cpp
        StandardCard.cpp
        PenaltyCard.cpp
        BonusCard.cpp
        Deck.cpp
        Player.cpp
        Game.cpp)
