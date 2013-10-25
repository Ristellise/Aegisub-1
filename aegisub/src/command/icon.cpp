// Copyright (c) 2010, Amar Takhar <verm@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#include "../config.h"

#include "icon.h"

#include <map>

#include <libaegisub/log.h>

#include "../libresrc/libresrc.h"

namespace icon {
typedef std::map<std::string, wxBitmap> iconMap;

iconMap icon16;
iconMap icon24;
iconMap icon32;

wxBitmap const& get(std::string const& name, const int size) {
	// XXX: This code will go away with dynamic icon generation so I'm not
	//      concerned about it.
	iconMap::iterator index;
	if (size == 32) {
		if ((index = icon32.find(name)) != icon32.end())
			return index->second;
	}
	else if (size == 24) {
		if ((index = icon24.find(name)) != icon24.end())
			return index->second;
	}
	else {
		if ((index = icon16.find(name)) != icon16.end())
			return index->second;
	}

	LOG_W("icon/get") << "Icon not found: " << name << " " << size;

	static wxBitmap bad;
	return bad;
}

#define INSERT_ICON(a, b) \
	icon16.insert(std::make_pair(a, GETIMAGE(b##_16))); \
	icon24.insert(std::make_pair(a, GETIMAGE(b##_24))); \
	icon32.insert(std::make_pair(a, GETIMAGE(b##_32)));

void icon_init() {
	// Seems that WX doesn't install the handlers early enough for our use.
	wxPNGHandler *handler = new wxPNGHandler();
	wxImage::AddHandler(handler);

	LOG_D("icon/init") << "Generating 24x24, 16x16 icons";

INSERT_ICON("am/manager", automation_toolbutton)
INSERT_ICON("am/meta", automation_toolbutton)
INSERT_ICON("app/about", about_menu)
INSERT_ICON("app/language", languages_menu)
INSERT_ICON("app/log", about_menu)
INSERT_ICON("app/new_window", new_window_menu)
INSERT_ICON("app/options", options_button)
INSERT_ICON("app/toggle/global_hotkeys", toggle_audio_medusa)
INSERT_ICON("audio/close", close_audio_menu)
INSERT_ICON("audio/commit", button_audio_commit)
INSERT_ICON("audio/go_to", button_audio_goto)
INSERT_ICON("audio/karaoke", kara_mode)
INSERT_ICON("audio/open", open_audio_menu)
INSERT_ICON("audio/open/video", open_audio_from_video_menu)
INSERT_ICON("audio/opt/autocommit", toggle_audio_autocommit)
INSERT_ICON("audio/opt/autonext", toggle_audio_nextcommit)
INSERT_ICON("audio/opt/autoscroll", toggle_audio_autoscroll)
INSERT_ICON("audio/opt/spectrum", toggle_audio_spectrum)
INSERT_ICON("audio/opt/vertical_link", toggle_audio_link)
INSERT_ICON("audio/play/selection", button_playsel)
INSERT_ICON("audio/play/line", button_playline)
INSERT_ICON("audio/play/selection/after", button_playfivehafter)
INSERT_ICON("audio/play/selection/before", button_playfivehbefore)
INSERT_ICON("audio/play/selection/begin", button_playfirstfiveh)
INSERT_ICON("audio/play/selection/end", button_playlastfiveh)
INSERT_ICON("audio/play/to_end", button_playtoend)
INSERT_ICON("audio/stop", button_stop)
INSERT_ICON("edit/color/primary", button_color_one);
INSERT_ICON("edit/color/secondary", button_color_two);
INSERT_ICON("edit/color/outline", button_color_three);
INSERT_ICON("edit/color/shadow", button_color_four);
INSERT_ICON("edit/font", button_fontname);
INSERT_ICON("edit/line/copy", copy_button)
INSERT_ICON("edit/line/cut", cut_button)
INSERT_ICON("edit/line/delete", delete_button)
INSERT_ICON("edit/line/paste", paste_button)
INSERT_ICON("edit/line/swap", arrow_sort)
INSERT_ICON("edit/style/bold", button_bold)
INSERT_ICON("edit/style/italic", button_italics)
INSERT_ICON("edit/style/strikeout", button_strikeout)
INSERT_ICON("edit/style/underline", button_underline)
INSERT_ICON("edit/redo", redo_button)
INSERT_ICON("edit/search_replace", find_replace_menu)
INSERT_ICON("edit/undo", undo_button)
INSERT_ICON("grid/line/next/create", button_audio_commit)
INSERT_ICON("grid/tag/cycle_hiding", toggle_tag_hiding)
INSERT_ICON("help/bugs", bugtracker_button)
INSERT_ICON("help/contents", contents_button)
INSERT_ICON("help/forums", forums_button)
INSERT_ICON("help/irc", irc_button)
INSERT_ICON("help/video", visual_help)
INSERT_ICON("help/website", website_button)
INSERT_ICON("keyframe/close", close_keyframes_menu)
INSERT_ICON("keyframe/open", open_keyframes_menu)
INSERT_ICON("keyframe/save", save_keyframes_menu)
INSERT_ICON("subtitle/attachment", attach_button)
INSERT_ICON("subtitle/find", find_button)
INSERT_ICON("subtitle/find/next", find_next_menu)
INSERT_ICON("subtitle/new", new_toolbutton)
INSERT_ICON("subtitle/open", open_toolbutton)
INSERT_ICON("subtitle/open/charset", open_with_toolbutton)
INSERT_ICON("subtitle/properties", properties_toolbutton)
INSERT_ICON("subtitle/save", save_toolbutton)
INSERT_ICON("subtitle/save/as", save_as_toolbutton)
INSERT_ICON("subtitle/select/visible", select_visible_button)
INSERT_ICON("subtitle/spellcheck", spellcheck_toolbutton)
INSERT_ICON("time/frame/current", shift_to_frame)
INSERT_ICON("time/lead/in", button_leadin)
INSERT_ICON("time/lead/out", button_leadout)
INSERT_ICON("time/next", button_next)
INSERT_ICON("time/prev", button_prev)
INSERT_ICON("time/shift", shift_times_toolbutton)
INSERT_ICON("time/snap/end_video", subend_to_video)
INSERT_ICON("time/snap/scene", snap_subs_to_scene)
INSERT_ICON("time/snap/start_video", substart_to_video)
INSERT_ICON("timecode/close", close_timecodes_menu)
INSERT_ICON("timecode/open", open_timecodes_menu)
INSERT_ICON("timecode/save", save_timecodes_menu)
INSERT_ICON("tool/assdraw", assdraw)
INSERT_ICON("tool/export", export_menu)
INSERT_ICON("tool/font_collector", font_collector_button)
INSERT_ICON("tool/line/select", select_lines_button)
INSERT_ICON("tool/resampleres", resample_toolbutton)
INSERT_ICON("tool/style/assistant", styling_toolbutton)
INSERT_ICON("tool/style/manager", style_toolbutton)
INSERT_ICON("tool/time/kanji", kara_timing_copier)
INSERT_ICON("tool/time/kanji", spellcheck_toolbutton)
INSERT_ICON("tool/time/postprocess", timing_processor_toolbutton)
INSERT_ICON("tool/translation_assistant", translation_toolbutton)
INSERT_ICON("video/close", close_video_menu)
INSERT_ICON("video/detach", detach_video_menu)
INSERT_ICON("video/details", show_video_details_menu)
INSERT_ICON("video/jump", jumpto_button)
INSERT_ICON("video/jump/end", video_to_subend)
INSERT_ICON("video/jump/start", video_to_substart)
INSERT_ICON("video/open", open_video_menu)
INSERT_ICON("video/open/dummy", use_dummy_video_menu)
INSERT_ICON("video/opt/autoscroll", toggle_video_autoscroll)
INSERT_ICON("video/play", button_play)
INSERT_ICON("video/play/line", button_playline)
INSERT_ICON("video/stop", button_pause)
INSERT_ICON("video/tool/clip", visual_clip)
INSERT_ICON("video/tool/cross", visual_standard)
INSERT_ICON("video/tool/drag", visual_move)
INSERT_ICON("video/tool/rotate/xy", visual_rotatexy)
INSERT_ICON("video/tool/rotate/z", visual_rotatez)
INSERT_ICON("video/tool/scale", visual_scale)
INSERT_ICON("video/tool/vector_clip", visual_vector_clip)
INSERT_ICON("video/zoom/in", zoom_in_button)
INSERT_ICON("video/zoom/out", zoom_out_button)

	// Remove the handler to avoid "Duplicate handler" warnings from WX since
	// it will attempt to install all the handlers later on.
	wxImage::RemoveHandler(handler->GetName());
}
} // namespace icon
