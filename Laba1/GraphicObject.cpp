#include "GraphicObject.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <iostream>
GraphicObject::GraphicObject(void) {

}

void GraphicObject::setPosition(float x, float y, float z) {
	position[0] = x;
	position[1] = y;
	position[2] = z;
}
void GraphicObject::setAngle(float a) {
	angle = a;
	glPushMatrix();
}
void GraphicObject::setColor(float r, float g, float b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}
void GraphicObject::draw(void) {
	glPushMatrix();
	glm::mat4 temp = glm::mat4(0);
	temp[0][0] = 1;
	temp[1][1] = 1;
	temp[2][2] = 1;
	temp[3][3] = 1;
	glm::mat4 temptr(0);
	temptr[0][0] = 1;
	temptr[1][1] = 1;
	temptr[2][2] = 1;
	temptr[3][3] = 1;
	temp[3][0] = 4;
	temptr = temptr * temp;
	std::cout << glm::to_string(temp) << std::endl;
	glMultMatrixf(glm::value_ptr(temp));
	glColor3f(color[0], color[1], color[2]);
	glutWireTeapot(1.0);

	glPopMatrix();
}

