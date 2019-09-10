#include "StoryMode.hpp"

#include "Sprite.hpp"
#include "DrawSprites.hpp"
#include "Load.hpp"
#include "data_path.hpp"
#include "gl_errors.hpp"
#include "MenuMode.hpp"

Sprite const *sprite_left_select = nullptr;
Sprite const *sprite_right_select = nullptr;

Sprite const *sprite_dunes_bg = nullptr;
Sprite const *sprite_dunes_traveller = nullptr;
Sprite const *sprite_dunes_ship = nullptr;

Sprite const *sprite_oasis_bg = nullptr;
Sprite const *sprite_oasis_bg_man = nullptr;
Sprite const *sprite_oasis_traveller = nullptr;

Sprite const *sprite_hill_bg = nullptr;
Sprite const *sprite_hill_traveller = nullptr;
Sprite const *sprite_hill_before = nullptr;
Sprite const *sprite_hill_after = nullptr;

const std::string text_dunes_landing = 
	"My name is Tom. You may Call me\n"
	"Major Tom. I lost contact with\n"
	"Ground Control. But Somehow I \n"
	"landed on the dark side of the Moon.\n"
	"I can see Planet Earth is blue.";
const std::string text_dunes_return = 
	"Come back to where I landed.\n"
	"There is nothing I can do.";

const std::string text_dunes_wont_leave = 
	"But I have no where to go.";
const std::string text_dunes_will_leave = 
	"The mysterious light reflection...\n"
	"What will happen next...?";
const std::string text_dunes_do_leave =
	". . .";
const std::string text_dunes_do_walk_east = 
	"Go down the Crater";
const std::string text_dunes_do_walk_west = 
	"Go up the Crater";

// ======================================
const std::string text_oasis_intro = 
	"I cannot believe there is water on the\n"
	"Moon.";
const std::string text_oasis_stone = 
	"I see an Oil Lamp inside the bush.";
const std::string text_oasis_plain = 
	"I still feel strange to see water here.";
const std::string text_oasis_end = 
	"\"It's our FATE!\" the stupid Lamp\n"
	"God shouted to me.";
const std::string text_oasis_stone_taken = 
	"I cannot picked up the Lamp. It's so\n"
	"heavy, though it is only a small Lamp.\n"
	"I wonder who would have lost it.";
const std::string text_oasis_saw_man = 
	"A strange man, or Lamp God, jumped\n"
	"out of the Lamp. \"My name is Sane.\n"
	"You must be Aladdin!\" Unfortunately,\n"
	"I am not. \"Whatever,\" the man said,\n"
	"\"I'm a Prophet. Answer one question\n"
	"and I'll know all about yourself.\"";
const std::string text_oasis_talked_with_man = 
	"\"Hah, tell me, if You can choose,\n"
	"which one will You choose to drink\n"
	"at this exact moment? Orange juice,\n"
	"cola, or beer?\"";
const std::string text_oasis_chose_orange = 
	"\"Hah, I have known all about You.\n"
	"You are a man who likes orange!";
const std::string text_oasis_chose_cola = 
	"\"Hah, I have known all about You.\n"
	"You are a man who likes cola!";
const std::string text_oasis_chose_beer = 
	"\"Hah, I have known all about You.\n"
	"You are a man who likes beer!";
const std::string text_oasis_sth_wrong = 
	"\"Hah, I have known all about You.\n"
	"You are a man who likes breaking\n"
	"the rules!";
const std::string text_oasis_finished_question = 
	"Hah! Ain't I a great Prophet?\n"
	"I'm such a genius hahaha!\"\n"
	"Bollocks. What a stupid Lamp God.";
const std::string text_oasis_boasted_man = 
	"\"Hah, You are right! Tell You one\n"
	"more thing. Our encounter is our\n"
	"FATE! Remember the word, 'FATE'!\"";
// -------
const std::string text_oasis_do_take_stone = 
	"Pick up the Lamp";
const std::string text_oasis_do_return = 
	"Return";

const std::string text_oasis_do_rub_lamp = 
	"Rub the Lamp";
const std::string text_oasis_do_talk_with_man = 
	"\"OK say your question\"";
const std::string text_oasis_do_not_talk_with_man = 
	"\"I take no interest\"";
const std::string text_oasis_do_choose_orange = 
	"\"Orange juice, of course\"";
const std::string text_oasis_do_choose_cola = 
	"\"I prefer cola\"";
const std::string text_oasis_do_choose_beer = 
	"\"I say beer\"";
const std::string text_oasis_do_boast_man = 
	"\"Oh You are definitely a genius\"";

// ======================================
const std::string text_hill_intro = 
	"I see a strange stone on the hill.\n"
	"There are words carved on it. Strange.\n"
	"Who would have built this?";
const std::string text_hill_inactive = 
	"The stone says, \"Write the WORDS\".\n"
	"There is a box carved under the words.";
const std::string text_hill_active = 
	"GOD. The stone turned an angle and\n"
	"started to reflect Sun light towards\n"
	"Planet Earth.";
const std::string text_hill_stone_added = 
	"I picked up a piece of hard rock and\n"
	"tried to carve the word \"FATE\" in\n"
	"the box.";
const std::string text_hill_do_add_stone = 
	"Carve \"FATE\"";
const std::string text_hill_do_return = 
	"Return";
// ======================================
const std::string text_main_title = 
	"Dark Side of\nthe Moon";
const std::string text_main_play_again = 
	"Play again";
const std::string text_main_play = 
	"Play";
const std::string text_main_exit = 
	"Exit";

Load< SpriteAtlas > sprites(LoadTagDefault, []() -> SpriteAtlas const * {
	SpriteAtlas const *ret = new SpriteAtlas(data_path("darkside-of-moon"));

	sprite_left_select = &ret->lookup("text-select-left");
	sprite_right_select = &ret->lookup("text-select-right");

	sprite_dunes_bg = &ret->lookup("dunes-bg");
	sprite_dunes_traveller = &ret->lookup("dunes-traveller");
	sprite_dunes_ship = &ret->lookup("dunes-ship");

	sprite_oasis_bg = &ret->lookup("oasis-bg");
	sprite_oasis_traveller = &ret->lookup("oasis-traveller");
	sprite_oasis_bg_man = &ret->lookup("oasis-bg-man");

	sprite_hill_bg = &ret->lookup("hill-bg");
	sprite_hill_traveller = &ret->lookup("hill-traveller");
	sprite_hill_before = &ret->lookup("hill-before");
	sprite_hill_after = &ret->lookup("hill-after");

	return ret;
});

StoryMode::StoryMode() {
}

StoryMode::~StoryMode() {
}

bool StoryMode::handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) {
	if (Mode::current.get() != this) return false;

	return false;
}

void StoryMode::update(float elapsed) {
	if (Mode::current.get() == this) {
		//there is no menu displayed! Make one:
		enter_scene();
	}
}

void StoryMode::reset_conditions() {
	have_stone = false;
	saw_man = false;
	talked_with_man = false;
	finished_question = false;
	boasted_man = false;
	added_stone = false;
	can_leave = false;
	which_to_drink = 0;

	dunes.first_visit = true;
	dunes.wont_leave = false;
	dunes.can_leave = false;
	
	oasis.first_visit = true;
	oasis.took_stone = false;
	oasis.saw_man = false;
	oasis.talked_with_man = false;
	oasis.finished_question = false;
	oasis.boasted_man = false;

	hill.first_visit = true;
	hill.known_answer = false;
	hill.added_stone = false;
}

void StoryMode::enter_scene() {
	//just entered this scene, adjust flags and build menu as appropriate:
	std::vector< MenuMode::Item > items;
	glm::vec2 at(3.0f, view_max.y - 3.0f);
	auto add_text = [&items,&at,this](std::string const &text, float scale=1.0f) {
		std::string sep = "\n";
		std::string token;
		
		// refer to https://stackoverflow.com/a/14267455
		size_t start = 0U;
		size_t end = text.find(sep);
		while (end != std::string::npos)
		{
			token = text.substr(start, end - start);
			items.emplace_back(token, nullptr, scale, nullptr, at);
			at.y -= choice_height * scale;
			at.y -= 4.0f * scale;

			start = end + sep.length();
			end = text.find(sep, start);
		}

		if (start < text.length()) {
			items.emplace_back(text.substr(start, text.length()), nullptr, scale, nullptr, at);
			at.y -= choice_height * scale;
			at.y -= 4.0f * scale;
		}
	};

	auto add_choice = [&items,&at,this](std::string const &text, std::function< void(MenuMode::Item const &) > const &fn, float scale=1.0f) {
		std::string sep = "\n";
		std::string token;
		
		// refer to https://stackoverflow.com/a/14267455
		size_t start = 0U;
		size_t end = text.find(sep);
		while (end != std::string::npos)
		{
			token = text.substr(start, end - start);
			items.emplace_back(token, nullptr, 1.0f, fn, at + glm::vec2(8.0f, 0.0f));
			at.y -= choice_height * scale;
			at.y -= 4.0f * scale;

			start = end + sep.length();
			end = text.find(sep, start);
		}

		if (start < text.length()) {
			items.emplace_back(text.substr(start, text.length()), nullptr, 1.0f, fn, at + glm::vec2(8.0f, 0.0f));
			at.y -= choice_height * scale;
			at.y -= 4.0f * scale;
		}
	};

	if (location == Main_memu) {
		add_text(text_main_title, 3.0);

		at.y -= 8.0f; //gap before choices
		if (main_memu.again) {
			add_choice(text_main_play_again, [this](MenuMode::Item const &){
				reset_conditions();
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		} else {
			add_choice(text_main_play, [this](MenuMode::Item const &){
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		}

		add_choice(text_main_exit, [this](MenuMode::Item const &){
			Mode::set_current(nullptr);
		});
	} else if (location == Dunes) {
		if (dunes.wont_leave) {
			dunes.wont_leave = false;
			add_text(text_dunes_wont_leave);
		} else if (added_stone) {
			add_text(text_dunes_will_leave);
		}
		if (dunes.first_visit) {
			dunes.first_visit = false;
			add_text(text_dunes_landing);
		} else if (!added_stone) {
			add_text(text_dunes_return);
		}
		at.y -= 8.0f; //gap before choices
		add_choice(text_dunes_do_walk_west, [this](MenuMode::Item const &){
			location = Hill;
			Mode::set_current(shared_from_this());
		});
		add_choice(text_dunes_do_walk_east, [this](MenuMode::Item const &){
			location = Oasis;
			Mode::set_current(shared_from_this());
		});
		if (!dunes.first_visit) {
			add_choice(text_dunes_do_leave, [this](MenuMode::Item const &){
				if (added_stone) {
					//TODO: some sort of victory animation?
					main_memu.again = true;
					location = Main_memu;
					Mode::set_current(shared_from_this());
				} else {
					dunes.wont_leave = true;
					Mode::set_current(shared_from_this());
				}
			});
		}
	} else if (location == Oasis) {
		if (oasis.took_stone) {
			oasis.took_stone = false;
			add_text(text_oasis_stone_taken);
		} else if (oasis.saw_man) {
			oasis.saw_man = false;
			add_text(text_oasis_saw_man);
		} else if (oasis.talked_with_man) {
			oasis.talked_with_man = false;
			add_text(text_oasis_talked_with_man);
		}else if (oasis.finished_question) {
			oasis.finished_question = false;
			switch (which_to_drink) {
			case 1:
				add_text(text_oasis_chose_orange);
				break;
			case 2:
				add_text(text_oasis_chose_cola);
				break;
			case 3:
				add_text(text_oasis_chose_beer);
				break;
			default:
				add_text(text_oasis_sth_wrong);
			}
			add_text(text_oasis_finished_question);
		} else if (oasis.boasted_man) {
			oasis.boasted_man = false;
			add_text(text_oasis_boasted_man);
		}

		if (oasis.first_visit) {
			oasis.first_visit = false;
			add_text(text_oasis_intro);
		}

		if (!have_stone) {
			add_text(text_oasis_stone);
		} else if (boasted_man) {
			add_text(text_oasis_end);
		} else {
			add_text(text_oasis_plain);
		}
		at.y -= 8.0f; //gap before choices
		if (!have_stone) {
			add_choice(text_oasis_do_take_stone, [this](MenuMode::Item const &){
				have_stone = true;
				oasis.took_stone = true;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_return, [this](MenuMode::Item const &){
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		} else if (!saw_man) {
			add_choice(text_oasis_do_rub_lamp, [this](MenuMode::Item const &){
				saw_man = true;
				oasis.saw_man = true;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_return, [this](MenuMode::Item const &){
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		} else if (!talked_with_man) {
			add_choice(text_oasis_do_talk_with_man, [this](MenuMode::Item const &){
				talked_with_man = true;
				oasis.talked_with_man = true;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_not_talk_with_man, [this](MenuMode::Item const &){
				oasis.saw_man = true;
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		} else if (!finished_question) {
			add_choice(text_oasis_do_choose_orange, [this](MenuMode::Item const &){
				finished_question = true;
				oasis.finished_question = true;
				which_to_drink = 1;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_choose_cola, [this](MenuMode::Item const &){
				finished_question = true;
				oasis.finished_question = true;
				which_to_drink = 2;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_choose_beer, [this](MenuMode::Item const &){
				finished_question = true;
				oasis.finished_question = true;
				which_to_drink = 3;
				Mode::set_current(shared_from_this());
			});
		} else if (!boasted_man) {
			add_choice(text_oasis_do_boast_man, [this](MenuMode::Item const &){
				boasted_man = true;
				oasis.boasted_man = true;
				Mode::set_current(shared_from_this());
			});
			add_choice(text_oasis_do_return, [this](MenuMode::Item const &){
				oasis.finished_question = true;
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		} else {
			add_choice(text_oasis_do_return, [this](MenuMode::Item const &){
				location = Dunes;
				Mode::set_current(shared_from_this());
			});
		}
	} else if (location == Hill) {
		if (hill.added_stone) {
			hill.added_stone = false;
			add_text(text_hill_stone_added);
		}

		if (hill.first_visit) {
			hill.first_visit = false;
			add_text(text_hill_intro);
		} else {
			if (added_stone) {
				add_text(text_hill_active);
			} else {
				add_text(text_hill_inactive);
			}
		}
		at.y -= 8.0f; //gap before choices
		if (boasted_man && !added_stone) {
			add_choice(text_hill_do_add_stone, [this](MenuMode::Item const &){
				added_stone = true;
				hill.added_stone = true;
				Mode::set_current(shared_from_this());
			});
		}
		add_choice(text_hill_do_return, [this](MenuMode::Item const &){
			location = Dunes;
			Mode::set_current(shared_from_this());
		});
	}
	std::shared_ptr< MenuMode > menu = std::make_shared< MenuMode >(items);
	menu->atlas = sprites;
	menu->left_select = sprite_left_select;
	menu->right_select = sprite_right_select;
	menu->view_min = view_min;
	menu->view_max = view_max;
	menu->background = shared_from_this();
	Mode::set_current(menu);
}

void StoryMode::draw(glm::uvec2 const &drawable_size) {
	//clear the color buffer:
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//use alpha blending:
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//don't use the depth test:
	glDisable(GL_DEPTH_TEST);

	{ //use a DrawSprites to do the drawing:
		DrawSprites draw(*sprites, view_min, view_max, drawable_size, DrawSprites::AlignPixelPerfect);
		glm::vec2 ul = glm::vec2(view_min.x, view_max.y);
		if (location == Dunes) {
			draw.draw(*sprite_dunes_bg, ul);
			draw.draw(*sprite_dunes_ship, ul);
			draw.draw(*sprite_dunes_traveller, ul);
		} else if (location == Oasis) {
			if (!saw_man) {
				draw.draw(*sprite_oasis_bg, ul);
			} else {
				draw.draw(*sprite_oasis_bg_man, ul);
			}
			draw.draw(*sprite_oasis_traveller, ul);

		} else if (location == Hill) {
			draw.draw(*sprite_hill_bg, ul);
			if (added_stone) {
				draw.draw(*sprite_hill_after, ul);
			} else {
				draw.draw(*sprite_hill_before, ul);
			}
			draw.draw(*sprite_hill_traveller, ul);
		} else {
			draw.draw(*sprite_dunes_bg, ul);
		}
	}
	GL_ERRORS(); //did the DrawSprites do something wrong?
}
