/*
** RPI Game Architecture Engine
**
** Portions adapted from:
** Viper Engine - Copyright (C) 2016 Velan Studios - All Rights Reserved
**
** This file is distributed under the MIT License. See LICENSE.txt.
*/

#include "ga_label.h"
#include "ga_font.h"

#include "framework/ga_frame_params.h"

ga_label::ga_label(const char* text, float x, float y, ga_frame_params* params)
{
	// TODO: Homework 4
	ga_vec3f color;
	color.x = 0;
	color.y = 0;
	color.z = 255;

	ga_vec2f _min;
	ga_vec2f _max;

	extern ga_font* g_font;
	g_font->print(params, text, x + 15, y + 5, color, &_min, &_max);
}

ga_label::~ga_label()
{
}
