/*
** EPITECH PROJECT, 2022
** kidiot.h
** File description:
** kidiot
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#define _GNU_SOURCE
#include "raylib.h"
#include "raymath.h"
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>


#include "list.h"

#define OBS_NBR 16
#define WALL_NBR 4

typedef struct bullet_s {
    Vector3 position;
    Vector3 direction;
    Model model;
    // Color colors;
    float speed;
    float size;
    struct bullet_s *next;
    struct bullet_s *head;
    bool isAlive;
} bullet_t;

typedef struct cube_s {
    Vector3 position;
    float width;
    float height;
    float length;
    Texture2D texture;
} cube_t;

typedef struct sprite_s {
    Texture2D texture;
    Vector2 position;
    Vector2 origin;
    float scale;
    Color tint;
} sprite_t;

typedef struct selection_menu_s {
    list_t *elements;

    Texture2D right_button;
    Rectangle right_sourceRec;
    Rectangle right_btnBounds;

    Texture2D left_button;
    Rectangle left_sourceRec;
    Rectangle left_btnBounds;

    Texture2D validate_button;
    Rectangle validate_sourceRec;
    Rectangle validate_btnBounds;
} selection_menu_t;

typedef struct menu_s {
    Camera camera;
    Vector2 mousePoint;

    Texture2D button;

    Rectangle sourceRec;
    Rectangle btnBounds;

    Texture2D quit_button;
    Rectangle quit_sourceRec;
    Rectangle quit_btnBounds;
    Vector2 quit_position;

    Texture2D title;

    int is_menu;
    Vector2 windowSize;
    selection_menu_t *selection_menu;
    Texture2D building;
    Texture2D ground;
} menu_t;

typedef struct {
    Camera camera;
    Vector3 cameraLastPosition;

    Vector2 windowSize;

    list_t *cube;
    list_t *bullet;

    menu_t *menu;
} game_t;

/**
 * @brief
 *
 * @param screenWidth
 * @param screenHeight
 */
void initWindow(const int screenWidth, const int screenHeight);

/**
 * @brief
 *
 * @param game
 */
void initWall(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initCamera(game_t *game);

/**
 * @brief
 *
 * @param speed
 * @param size
 * @param camera
 * @return bullet_t*
 */
void initBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void initGame(game_t *game);

// CREATE

/**
 * @brief Create a Bullet object
 *
 * @param game
 * @param speed
 * @param size
 */
void createBullet(game_t *game, float speed, float size);

// UPDATE

/**
 * @brief
 *
 * @param game
 */
void updateEnter(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateEvent(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void checkCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateCollision(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateDeadBullet(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void updateGame(game_t *game);

// DRAW

/**
 * @brief
 *
 * @param game
 */
void drawGame(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawCube(game_t *game);

/**
 * @brief
 *
 * @param game
 */
void drawBullet(game_t *game);

// MAIN

/**
 * @brief
 *
 * @param game
 */
void mainLoop(game_t *game);

/**
 * @brief
 *
 * @param menu_st
 */
void initMenu(game_t *game);

/**
 * @brief
 *
 * @param menu_st
 * @return int
 */
int menu(menu_t *menu_st);

#endif /* !CLIENT_H_ */
