int vertical = 1;
int maxButtonsOnRow = 9;

struct shortcutDef {
	int id;
	const char* label;
	const char* action;
};

static struct shortcutDef shortcutID[] = {
	{ 1, "Execute xterm", "xterm &" },
	{ 2, "Execute Top", "xterm -e top &" },
	{ 3, "Execute calc", "xcalc &" },
	{ 4, "Execute xeyes", "xeyes &" },
};
