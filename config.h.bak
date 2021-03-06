/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 5;
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "dev", "sys", "www", "mail", "play", "med", "chat", "virt", "tor" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "termite", NULL };
static const char *doom[]     = { "/home/magneto/.emacs.d/bin/doom", "run", NULL };
static const char *firefox[]  = { "firefox", NULL };
static const char *spotify[]  = { "spotify", NULL };
static const char *thunderbird[]  = { "thunderbird", NULL };
static const char *keepassxc[]  = { "keepassxc", NULL };
static const char *librewolf[]  = { "librewolf", NULL };
static const char *librewolfPrivate[]  = { "librewolf", "-private-window", NULL };
static const char *brave[]  = { "brave", "-private-window", NULL };
static const char *bravePrivate[]  = { "brave", "-private-window", NULL };
static const char *chrome[]  = { "google-chorme-stable", NULL };
static const char *chromium[]  = { "chromium", NULL };
static const char *vscode[]  = { "vscode", NULL };
static const char *vim[]  = { "termite", "-e", "vim", NULL };
static const char *popcorntime[]  = { "popcorntime", NULL };
static const char *ranger[]  = { "termite", "-e", "ranger", NULL };
static const char *steam[]  = { "steam-runtime", NULL };
static const char *lutris[]  = { "lutris", NULL };
static const char *transmission[]  = { "transmission-gtk", NULL };
static const char *telegram[]  = { "telegram-desktop", NULL };
static const char *blueman[]  = { "blueman-manager", NULL };
static const char *nmdmenu[]  = { "networkmanager_dmenu", NULL };
static const char *vlc[]  = { "vlc", NULL };
static const char *pavucontrol[]  = { "pavucontrol", NULL };
static const char *i3lock[]  = { "sh", "/home/magneto/.config/i3/scripts/.lock.sh", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = librewolf } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = librewolfPrivate } },
	{ MODKEY|ControlMask,           XK_w,      spawn,          {.v = brave } },
	{ MODKEY|Mod1Mask,              XK_w,      spawn,          {.v = bravePrivate } },
	{ MODKEY,                       XK_e,      spawn,          {.v = doom } },
	{ MODKEY|ShiftMask,             XK_e,      spawn,          {.v = vscode } },
	{ MODKEY|ControlMask,           XK_e,      spawn,          {.v = vim } },
	{ MODKEY,                       XK_r,      spawn,          {.v = ranger } },
	{ MODKEY,                       XK_t,      spawn,          {.v = transmission } },
	{ MODKEY|ShiftMask,             XK_t,      spawn,          {.v = telegram } },
	{ MODKEY,                       XK_p,      spawn,          {.v = keepassxc } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = pavucontrol } },
	{ MODKEY,                       XK_s,      spawn,          {.v = spotify } },
	{ MODKEY|ShiftMask,             XK_s,      spawn,          {.v = vlc } },
	{ MODKEY|ControlMask,           XK_s,      spawn,          {.v = popcorntime } },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_f,      spawn,          {.v = firefox } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = chrome } },
	{ MODKEY|ControlMask,           XK_f,      spawn,          {.v = chromium } },
	{ MODKEY,                       XK_g,      spawn,          {.v = steam } },
	{ MODKEY|ShiftMask,             XK_g,      spawn,          {.v = lutris } },
	{ MODKEY,                       XK_n,      spawn,          {.v = blueman } },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          {.v = nmdmenu } },
	{ MODKEY,                       XK_m,      spawn,          {.v = thunderbird } },
	{ MODKEY,                       XK_b,      spawn,          {.v = i3lock } },

	{ MODKEY,                       XK_v,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	// { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

