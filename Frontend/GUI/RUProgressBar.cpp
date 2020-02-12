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
#include "RUProgressBar.h"
#include "../GItems/RUColors.h"

RUProgressBar::RUProgressBar()
{
	value = 0;
	maxValue = 0;
	toggleBorder(true);
	barColor = RUColors::DEFAULT_COLOR_PROGRESS_BAR;
	setBGColor(RUColors::DEFAULT_COLOR_BACKGROUND);
}

RUProgressBar::RUProgressBar(int newMaxValue)
{
	value = 0;
	maxValue = newMaxValue;
	toggleBorder(true);
	barColor = RUColors::DEFAULT_COLOR_PROGRESS_BAR;
	setBGColor(RUColors::DEFAULT_COLOR_BACKGROUND);
}

RUProgressBar::~RUProgressBar()
{
	value = 0;
	maxValue = 0;
	toggleBorder(true);
}

int RUProgressBar::getValue() const
{
	return value;
}

int RUProgressBar::getMaxValue() const
{
	return maxValue;
}

void RUProgressBar::setValue(int newValue)
{
	value = newValue;
	if (value < 0)
		value = 0;
	else if (value > maxValue)
		value = maxValue;

	drawUpdate = true;
}

void RUProgressBar::setMaxValue(int newMaxValue)
{
	maxValue = newMaxValue;
	if (maxValue < 0)
		maxValue = 0;

	drawUpdate = true;
}

void RUProgressBar::updateBackground(SDL_Renderer* renderer)
{
	// draw the bar
	SDL_Rect barRect;
	barRect.x = 0;
	barRect.y = 0;
	barRect.w = (((float)value) / ((float)maxValue)) * width;
	barRect.h = height;

	SDL_SetRenderDrawColor(renderer, barColor.r, barColor.g, barColor.b, SDL_ALPHA_OPAQUE);
	SDL_RenderFillRect(renderer, &barRect);
}

std::string RUProgressBar::getType() const
{
	return "RUProgressBar";
}
