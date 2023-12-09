int vertical = 0;
int maxButtonsOnRow = 3;

struct shortcutDef {
	int id;
	const char* label;
	const char* action;
};

static struct shortcutDef shortcutID[] = {
	{ 1, "Execute Top", "xterm -e top &" },
};
