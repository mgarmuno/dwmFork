/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 1;        /* border pixel of windows */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int gappih         = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;       /* vert inner gap between windows */
static const unsigned int gappoh         = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps               = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;
static const int showsystray             = 1;     /* 0 means no systray */
static const int showbar                 = 1;        /* 0 means no bar */
static const int topbar                  = 1;        /* 0 means bottom bar */
static const char *fonts[]               = { "Hack:style=Regular:size=10","Symbols Nerd Font:pixelsize=11:antialias=true;autohint=true" };
static const char dmenufont[]            = "Hack:size=9";
static const char col_gray1[]            = "#282A36";
static const char col_gray2[]            = "#282A36";
static const char col_gray3[]            = "#F8F8F2";
static const char col_gray4[]            = "#282A36";
static const char col_cyan[]             = "#BD93F9";
static const char *colors[][3]           = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "","", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "tk",       NULL,       "Bookmarks",     0,      1,           -1 },
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
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]           = { "alacritty", NULL };
static const char *shutdown[]          = { "shutdown",  "-h", "now", NULL };
static const char *restart[]           = { "reboot", NULL };
static const char *firefox[]           = { "firefox", NULL };
static const char *firefoxpriv[]       = { "firefox", "-private-window", NULL };
static const char *spotify[]           = { "spotify", NULL };
static const char *thunderbird[]       = { "thunderbird", NULL };
static const char *keepassxc[]         = { "keepassxc", NULL };
static const char *librewolf[]         = { "librewolf", NULL };
static const char *librewolfPrivate[]  = { "librewolf", "-private-window", NULL };
static const char *brave[]             = { "brave", "-private-window", NULL };
static const char *bravePrivate[]      = { "brave", "-private-window", NULL };
static const char *chrome[]            = { "google-chrome-stable", NULL };
static const char *chromium[]          = { "chromium", NULL };
static const char *vscode[]            = { "code", NULL };
static const char *vim[]               = { "alacritty", "-e", "vim", NULL };
static const char *popcorntime[]       = { "popcorntime", NULL };
static const char *ranger[]            = { "alacritty", "-e", "ranger", NULL };
static const char *pcmanfm[]           = { "pcmanfm", NULL };
static const char *steam[]             = { "steam-runtime", NULL };
static const char *lutris[]            = { "lutris", NULL };
static const char *transmission[]      = { "transmission-gtk", NULL };
static const char *telegram[]          = { "telegram-desktop", NULL };
static const char *blueman[]           = { "blueman-manager", NULL };
static const char *nmdmenu[]           = { "networkmanager_dmenu", NULL };
static const char *vlc[]               = { "smplayer", NULL };
static const char *pavucontrol[]       = { "pavucontrol", NULL };
static const char *i3lock[]            = { "sh", "/home/magneto/.config/mscripts/.lock.sh", NULL };
static const char *clipGoShow[]        = { "/home/magneto/go/bin/clipGo", "show", NULL };
static const char *clipGoDelete[]      = { "/home/magneto/go/bin/clipGo", "delete", NULL };
static const char *cliplistner[]       = { "sh", "/home/magneto/.config/mtools/cliplistner.sh", NULL };
static const char *amixdownvol[]       = { "amixer", "-q", "-D", "pulse", "set", "Master", "2%-", "unmute",   NULL };
static const char *amixupvol[]         = { "amixer", "-q", "-D", "pulse", "set", "Master", "2%+", "unmute",   NULL };
static const char *amixmutevol[]       = { "amixer", "-q", "set", "Master", "mute",  NULL };
static const char *brightdown[]        = { "pkexec", "/usr/bin/brillo", "-U", "2", NULL };
static const char *brightup[]          = { "pkexec", "/usr/bin/brillo", "-A", "2", NULL };
static const char *playpause[]         = { "payerctl", "play-pause", NULL };
static const char *nextmedia[]         = { "payerctl", "next", NULL };
static const char *prevmedia[]         = { "payerctl", "previus", NULL };
static const char *flameshot[]         = { "flameshot", "gui", NULL };

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                XK_Return,                 spawn,          {.v = termcmd } },
	{ MODKEY,                XK_w,                      spawn,          {.v = librewolf } },
	{ MODKEY|ShiftMask,      XK_w,                      spawn,          {.v = librewolfPrivate } },
	{ MODKEY|ControlMask,    XK_w,                      spawn,          {.v = brave } },
	{ MODKEY|Mod1Mask,       XK_w,                      spawn,          {.v = bravePrivate } },
	{ MODKEY,                XK_e,                      spawn,          {.v = vim } },
	{ MODKEY|ShiftMask,      XK_e,                      spawn,          {.v = vscode } },
	{ MODKEY,                XK_r,                      spawn,          {.v = ranger } },
	{ MODKEY|ShiftMask,      XK_r,                      spawn,          {.v = pcmanfm } },
	{ MODKEY,                XK_t,                      spawn,          {.v = transmission } },
	{ MODKEY|ShiftMask,      XK_t,                      spawn,          {.v = telegram } },
	{ MODKEY,                XK_p,                      spawn,          {.v = keepassxc } },
	{ MODKEY|ShiftMask,      XK_p,                      spawn,          {.v = pavucontrol } },
	{ MODKEY,                XK_s,                      spawn,          {.v = spotify } },
	{ MODKEY|ShiftMask,      XK_s,                      spawn,          {.v = vlc } },
	{ MODKEY|ControlMask,    XK_s,                      spawn,          {.v = popcorntime } },
	{ MODKEY,                XK_d,                      spawn,          {.v = dmenucmd } },
	{ MODKEY,                XK_f,                      spawn,          {.v = firefox } },
	{ MODKEY|Mod1Mask,       XK_f,                      spawn,          {.v = firefoxpriv } },
	{ MODKEY|ShiftMask,      XK_f,                      spawn,          {.v = chrome } },
	{ MODKEY|ControlMask,    XK_f,                      spawn,          {.v = chromium } },
	{ MODKEY,                XK_g,                      spawn,          {.v = steam } },
	{ MODKEY|ShiftMask,      XK_g,                      spawn,          {.v = lutris } },
	{ MODKEY,                XK_c,                      spawn,          {.v = clipGoShow } },
	{ MODKEY|ShiftMask,      XK_c,                      spawn,          {.v = clipGoDelete } },
	{ MODKEY|ControlMask,    XK_c,                      spawn,          {.v = cliplistner } },
	{ MODKEY,                XK_b,                      spawn,          {.v = i3lock } },
	{ MODKEY,                XK_n,                      spawn,          {.v = blueman } },
	{ MODKEY|ShiftMask,      XK_n,                      spawn,          {.v = nmdmenu } },
	{ MODKEY,                XK_m,                      spawn,          {.v = thunderbird } },
	{ 0,                     XK_Print,                  spawn,          {.v = flameshot } },

	{ 0,                     XF86XK_AudioRaiseVolume,   spawn,          {.v = amixupvol } },
	{ 0,                     XF86XK_AudioLowerVolume,   spawn,          {.v = amixdownvol } },
	{ 0,                     XF86XK_AudioMute,          spawn,          {.v = amixmutevol } },
	{ 0,                     XF86XK_AudioPlay,          spawn,          {.v = prevmedia } },
	{ 0,                     XF86XK_AudioNext,          spawn,          {.v = nextmedia } },
	{ 0,                     XF86XK_AudioPrev,          spawn,          {.v = playpause } },
	{ MODKEY,                XK_F1,                     spawn,          {.v = amixdownvol } },
	{ MODKEY,                XK_F2,                     spawn,          {.v = amixupvol } },
	{ MODKEY,                XK_F3,                     spawn,          {.v = brightdown } },
	{ MODKEY,                XK_F4,                     spawn,          {.v = brightup } },
	{ MODKEY,                XK_F5,                     spawn,          {.v = prevmedia } },
	{ MODKEY,                XK_F6,                     spawn,          {.v = nextmedia } },
	{ MODKEY,                XK_F7,                     spawn,          {.v = playpause } },

	{ MODKEY|Mod1Mask,              XK_h,              incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_l,              incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_h,              incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_l,              incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_h,              incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ControlMask,  XK_l,              incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_Delete,              togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_Delete,              defaultgaps,    {0} },
	{ MODKEY|ControlMask,           XK_y,              incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,              incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_y,              incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask,              XK_o,              incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,              incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,              incrovgaps,     {.i = -1 } },

	{ MODKEY,                XK_v,                      togglebar,      {0} },
	{ MODKEY,                XK_j,                      focusstack,     {.i = +1 } },
	{ MODKEY,                XK_k,                      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                XK_i,                      incnmaster,     {.i = +1 } },
	{ MODKEY,                XK_o,                      incnmaster,     {.i = -1 } },
	{ MODKEY,                XK_h,                      setmfact,       {.f = -0.01} },
	{ MODKEY,                XK_l,                      setmfact,       {.f = +0.01} },
	{ MODKEY|ShiftMask,      XK_Return,                 zoom,           {0} },
	{ MODKEY,                XK_Tab,                    view,           {0} },
	{ MODKEY,                XK_q,                      killclient,     {0} },
	{ MODKEY,                XK_z,                      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,      XK_z,                      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,      XK_space,                  setlayout,      {0} },
	{ MODKEY,                XK_space,                  togglefloating, {0} },
	{ MODKEY|ShiftMask,      XK_0,                      tag,            {.ui = ~0 } },
	{ MODKEY,                XK_comma,                  focusmon,       {.i = -1 } },
	{ MODKEY,                XK_period,                 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,      XK_comma,                  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,      XK_period,                 tagmon,         {.i = +1 } },
	TAGKEYS(                 XK_1,                      0)
	TAGKEYS(                 XK_2,                      1)
	TAGKEYS(                 XK_3,                      2)
	TAGKEYS(                 XK_4,                      3)
	TAGKEYS(                 XK_5,                      4)
	TAGKEYS(                 XK_6,                      5)
	TAGKEYS(                 XK_7,                      6)
	TAGKEYS(                 XK_8,                      7)
	TAGKEYS(                 XK_9,                      8)
	TAGKEYS(                 XK_0,                      9)
	TAGKEYS(                 XK_minus,                  10)
	TAGKEYS(                 XK_equal,                  11)
	{ MODKEY|ShiftMask,      XK_BackSpace,              quit,           {0} },
	{ MODKEY|ControlMask,    XK_BackSpace,              spawn,          {.v = shutdown} },
	{ MODKEY|Mod1Mask,       XK_BackSpace,              spawn,          {.v = restart} },
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

