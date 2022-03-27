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

ga_button::ga_button(const char* text, float x, float y, ga_frame_params* params)
{
	ga_widget gw;
	extern ga_font* g_font;
	g_font->print(params, text, x, y, gw.k_text_color, &_min, &_max);

	if (get_pressed(params)) {	
		ga_widget::draw_outline(params, _min, _max, gw.k_button_press_color, gw.k_button_offset);
	}
	
	else if (get_hover) {
		ga_widget::draw_outline(params, _min, _max, gw.k_button_hover_color, gw.k_button_offset);
	}

	else {
		ga_widget::draw_outline(params, _min, _max, gw.k_button_color, gw.k_button_offset);
	}
}

ga_button::~ga_button()
{
}

bool ga_button::get_hover(const ga_frame_params* params) const
{
	
	return 
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;
}

bool ga_button::get_pressed(const ga_frame_params* params) const
{

	return params->_mouse_press_mask != 0 && get_hover(params);
}

bool ga_button::get_clicked(const ga_frame_params* params) const
{
	return params->_mouse_click_mask != 0 && get_hover(params);
}
