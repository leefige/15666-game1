
/*
 * StoryMode implements a story about The Planet of Choices.
 *
 */

#include "Mode.hpp"

struct StoryMode : Mode {
	StoryMode();
	virtual ~StoryMode();

	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//called to create menu for current scene:
	void enter_scene();
	void reset_conditions();

	//------ story state -------
	enum {
		Dunes,
		Oasis,
		Hill,
		Main_memu
	} location = Main_memu;

	bool have_stone = false;
	bool saw_man = false;
	bool talked_with_man = false;
	bool finished_question = false;
	bool boasted_man = false;
	bool added_stone = false;
	bool can_leave = false;
	int which_to_drink = 0;
	struct {
		bool first_visit = true;
		bool wont_leave = false;
		bool can_leave = false;
	} dunes;
	struct {
		bool first_visit = true;
		bool took_stone = false;
		bool saw_man = false;
		bool talked_with_man = false;
		bool finished_question = false;
		bool boasted_man = false;
	} oasis;
	struct {
		bool first_visit = true;
		bool known_answer = false;
		bool added_stone = false;
	} hill;
	struct {
		bool again = false;
	} main_memu;
	
	glm::vec2 view_min = glm::vec2(0,0);
	glm::vec2 view_max = glm::vec2(256, 224);

	float text_height = 12;
	float choice_height = text_height;
};
