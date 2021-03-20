/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_button.h"
#include "ga_font.h"

#include "framework/ga_frame_params.h"

#include <stdio.h>
#include <iostream>

ga_button::ga_button(const char* text, float x, float y, ga_frame_params* params)
{
	// TODO: Homework 4
	// hint, first draw the text, then decide what else to draw based on the get functions below

	_min.x = x - 10;
	_min.y = y - 10;
	_max.x = x + 10;
	_max.y = y + 10;
	ga_vec3f color;
	color.x = 0;
	color.y = 0;
	color.z = 255;
	float offset = 0;

	extern ga_font* g_font;
	g_font->print(params, text, x + 15, y + 5, color, &_min, &_max);

	draw_outline(params, _min, _max, color, offset);

	if (get_hover(params)) { draw_fill(params, _min, _max, color); /*std::cout << "AA" << std::endl;*/ }
}

ga_button::~ga_button()
{
}

bool ga_button::get_hover(const ga_frame_params* params) const
{
	// TODO: Homework 4
	
	bool click_in_region =
		//params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;

	return click_in_region;
}

bool ga_button::get_pressed(const ga_frame_params* params) const
{
	// TODO: Homework 4
	return false;
}

bool ga_button::get_clicked(const ga_frame_params* params) const
{
	// TODO: Homework 4
	
	bool click_in_region =
		params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;

	return click_in_region;
}
