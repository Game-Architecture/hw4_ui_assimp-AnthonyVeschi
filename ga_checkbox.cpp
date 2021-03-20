/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_checkbox.h"
#include "ga_font.h"

#include "framework/ga_frame_params.h"

ga_checkbox::ga_checkbox(bool state, const char* text, float x, float y, ga_frame_params* params)
{
	// TODO: Homework 4

	_min.x = x - 10;
	_min.y = y - 10;
	_max.x = x + 10;
	_max.y = y + 10;
	ga_vec3f color;
	color.x = 0;
	color.y = 0;
	color.z = 255;
	float offset = 0;
	draw_outline(params, _min, _max, color, offset);

	if (state) { draw_check(params, _min, _max, color); }

	extern ga_font* g_font;
	g_font->print(params, text, x+15, y+5, color, &_min, &_max);
}

ga_checkbox::~ga_checkbox()
{
}

bool ga_checkbox::get_hover(const ga_frame_params* params) const
{
	// TODO: Homework 4
	
	bool click_in_region =
		//params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x-30 &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x-180 &&
		params->_mouse_y <= _max.y;

	return click_in_region;
}

bool ga_checkbox::get_pressed(const ga_frame_params* params) const
{
	// TODO: Homework 4
	return false;
}

bool ga_checkbox::get_clicked(const ga_frame_params* params) const
{
	// TODO: Homework 4
	
	bool click_in_region =
		params->_mouse_click_mask != 0 &&
		params->_mouse_x >= _min.x-30 &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x-180 &&
		params->_mouse_y <= _max.y;

	return click_in_region;
}
