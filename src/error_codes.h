#ifndef _ERROR_CODES_
#define _ERROR_CODES_ value

typedef enum 
{
	ECODE_OK=0,
	ECODE_IO,
	
	ECODE_GL,
	ECODE_GLEW,

	ECODE_SDL_INIT,
	ECODE_SDL_WINDOW,
	ECODE_SDL_GL_CONTEXT,
	ECODE_SDL_VSYNC
} error_code;


#endif /* _ERROR_CODES_ */