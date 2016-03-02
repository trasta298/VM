#include "mcpe/Gui.h"

class Player;

class MinecraftClient{
public:
	Gui *getGui();
	void onPlayerLoaded(Player &);
};