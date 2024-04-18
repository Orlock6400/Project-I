#include <iostream>
#include "raylib.h"

//constants globals


//window size
#define WINDOW_WIDTH 224
#define WINDOW_HEIGHT 288

//velocities
#define PLAYER_SPEED 3
#define GHOST_SPEED 10

//classes
typedef struct Player {
	Vector2 Pos;
	int width, height;
	int speed;
	short lives;
	bool is_alive;
};

typedef struct Ghost {
	Vector2 pos;
	int width, height;
	int speed;
};

//VARIABLES GLOBALS
Player player;

//fantasmes
Ghost red, blue, orange, pink;

//comprova si toca una paret
bool colision;

int pellets_eaten;
bool superMode;
int score;
bool godMode;

//TEMPORAL

//textures
Texture imgPacMan, imgBackground, imgRedGhost, imgBlueGhost, imgPinkGhost, imgOrangeGhost;

//Basic structure functions
void Setup();
bool Update();
void Render();
void Cleanup();

//Auxiliar functions
bool LoadTextures();
void UnloadTextures();

int main() {

	Setup();
	while (!WindowShouldClose())
	{
		if (!Update()) break;
		Render();
	}
	Cleanup();

	return 0;
}

void Setup() {
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "PAC-MAN");

	//load textures
	if (!LoadTextures()) {
		printf("Failed to load textures");
		CloseWindow();
		return;
	}

	//initialize player

	//inicialitzem background & limits

	//inicialitzem pellets i powerups

	//inicialitzem fantasmes

	//variables de control
	godMode = false;

	//set FPS
	SetTargetFPS(60);
}

bool LoadTextures() {
	//imatges
	//exemple:
	//img_background = LoadTexture("images/background.png");
	//if (img_background.id == 0) return false;
	return true;
}

bool Update() {
	int px = 0, py = 0; //direcció pacman

	if (IsKeyDown(KEY_ESCAPE))  return false;
	if (IsKeyPressed(KEY_F1))   godMode = !godMode;

	//py i px agafen valor segons direcció donada (fletxes)
	if (IsKeyDown(KEY_UP))		py = -1;
	if (IsKeyDown(KEY_DOWN))	py = 1;
	if (IsKeyDown(KEY_LEFT))    px = -1;
	if (IsKeyDown(KEY_RIGHT))	px = 1;

	//pac-man movement
	player.Pos.x += px * PLAYER_SPEED;
	player.Pos.y += py * PLAYER_SPEED;


	return true;
}

void Render() {
	BeginDrawing();
	ClearBackground(BLACK);

	//render escena

	//render punts

	//render contador de punts i fruites recollides (lletres?)

	//render friuta si està

	//render pac-man
	DrawCircle(player.Pos.x, player.Pos.y, 5, YELLOW);

	//render fantasmes

	//render hitboxes si està en godmode
	if (godMode) {

	}

	EndDrawing();

}

void Cleanup() {
	UnloadTextures();
}
void UnloadTextures() {
	//un unload texture per a cada textura
}
