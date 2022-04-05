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
	ga_widget gw;
	extern ga_font* g_font;
	g_font->print(params, text, x + k_checkbox_offset, y, gw.k_text_color, &_min, &_max);

	_min = { x, _min.y };
	_max = { x + (_max.y - _min.y), _max.y };

	ga_widget::draw_outline(params, _min, _max, gw.k_button_color, gw.k_checkbox_offset);

	if (state) {
		ga_widget::draw_check(params, _min, _max, gw.k_button_color);
	}

}

ga_checkbox::~ga_checkbox()
{
}

bool ga_checkbox::get_hover(const ga_frame_params* params) const
{

	return
		params->_mouse_x >= _min.x &&
		params->_mouse_y >= _min.y &&
		params->_mouse_x <= _max.x &&
		params->_mouse_y <= _max.y;
}

bool ga_checkbox::get_pressed(const ga_frame_params* params) const
{
	return params->_mouse_press_mask != 0 && get_hover(params);
}

bool ga_checkbox::get_clicked(const ga_frame_params* params) const
{
	return params->_mouse_click_mask != 0 && get_hover(params);
}
