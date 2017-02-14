#include <GL/glew.h>
#include <GL/glu.h>

#include <stdio.h>
#include <err.h>

#include "IO_funcs.h"
#include "image.h"
#include "bmp.h"
#include "texture.h"

GLuint load_texture( image_t* image
	){
	GLuint textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	glTexImage2D(
		GL_TEXTURE_2D, 0,
		GL_RGB, image->width, image->height, 0,
		GL_BGR,
		GL_UNSIGNED_BYTE,
		image->pixels);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

/*
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
*/

	return textureID;
}

#define WARN_HEADER "[load_BMPtexture]"

GLuint fload_BMP_texture( const char* filename ){
	FILE* 	f;
	image_t* image;
	IO_stat_t status;
	GLuint textureID;

	f = fopen(filename, "r");
	if( NULL == f ) {
		warnx("%s: file wasn't found: %s\n", WARN_HEADER, filename);
		return 0;
	}

	status = load_BMP24(f, &image, NULL);
	if ( IO_OK != status ){
		warnx("%s: BMP loading error with code %d", WARN_HEADER, status);
		return 0;
	}

	printf("[Texture Loaded] %s, %dx%d\n", filename, image->width, image->height);

	textureID = load_texture(image);

	free_image(image);
	return textureID;
}