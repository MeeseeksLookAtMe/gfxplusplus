// Copyright 2020 Robert Carneiro, Derek Meer, Matthew Tabak, Eric Lujan
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#ifndef _GRAPHICS
#define _GRAPHICS

#include "../GFXUtilities/quaternion.h"
#include "../GItems/GItem.h"
#include "../GItems/GLayout.h"
#include "../GItems/GPanel.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

class GItem;
class RUComponent;
class RULabel;
class GPanel;
class Object;
class GFont;

class gfxpp
{
	friend class RUComponent;
	friend class RUTextComponent;
	friend class RUImageComponent;
	friend class RUButton;
	friend class RULabel;
	friend class RUTextbox;
	friend class RUGraph;
	friend class RUProgressBar;
	friend class RUScrollbar;
	friend class RUListbox;
	friend class RUDropdown;
	friend class RUKeyDown;
	friend class RUKeyUp;

private:
	int errorFlag;
	bool running;
	int width;
	int height;
	float hunterZolomon; // zoom
	int renderStatus;

	int32_t frames;
	bool rotate;
	bool move;
	int32_t now;
	int32_t then;

	// for mouse
	int mouseX;
	int mouseY;

	// for key presses
	bool CTRLPressed;
	bool ALTPressed;
	bool spacePressed;
	bool fPressed;
	bool uPressed;
	bool qPressed;
	bool gPressed;
	bool rPressed;
	bool lPressed;
	bool upPressed;
	bool downPressed;
	bool leftPressed;
	bool rightPressed;

	Quaternion roll;
	Quaternion pitch;
	Quaternion yaw;

	SDL_Window* window;
	SDL_GLContext context;
	SDL_Renderer* renderer;

	std::vector<GItem*> guiElements; // < RUComponent* || GLayout* >

	GItem* focusedItem;
	std::vector<Object*> objects;
	unsigned int cObjIndex;

	// default gui
	RULabel* fpsLabel;

	// main
	void display();
	int initHelper(bool, std::string);
	int init2D();
	void init3D();
	void clean2D();
	void clean3D();

public:
	static const float MAX_FRAMES_PER_SECOND = 30.0f;

	static const int _2D = 0;
	static const int _3D = 1;

	static const int X_AXIS = 0;
	static const int Y_AXIS = 1;
	static const int Z_AXIS = 2;

	gfxpp();
	gfxpp(std::string, int = _2D, bool = true, int = 800, int = 600);
	int getErrorFlag() const;
	SDL_Renderer* getRenderer();

	// GFX Utils
	static unsigned int RGBfromHue(double, int8_t*, int8_t*, int8_t*);
	bool contains(const Object*) const;
	bool contains(const Object) const;

	// 2D
	GFont* cFont;
	std::map<std::string, GFont*> graphicsFonts;

	GPanel* focusedPanel;
	void addGradient(int, int, int);
	void addItem(GItem*);
	void removeItem(int); // id
	GItem* getItemByID(int);
	void setFocus(GItem*);
	int getWidth() const;
	int getHeight() const;

	// 3D
	void addBasis();
	void addCube();

	// main
	void run();
	void changeRenderStatus(int);
	void finish();
};

#endif
