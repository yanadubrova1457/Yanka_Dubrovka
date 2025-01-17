// #include <iostream>
// #include <vector>
//
// #define GLM_ENABLE_EXPERIMENTAL
// #include <glm/glm.hpp>
// #include <glm/gtx/matrix_transform_2d.hpp>
// #include <glm/gtx/euler_angles.hpp>
// #include <ppgso/ppgso.h>
//
// #include <shaders/color_vert_glsl.h>
// #include <shaders/color_frag_glsl.h>
//
// #include "../scene.cpp"
//
// #include "../renderable.h"
// #include "../camera.h"
//
//
// #ifndef CUBE
// #define CUBE
// // Object to represent a 3D cube
// class Cube : public Renderable
// {
// private:
// 	// 2D vectors define points/vertices of the shape
// 	// Define cube vertices
// 	std::vector<glm::vec3> vertices = {
// 		// front
// 		{-1, -1, 1},
// 		{1, -1, 1},
// 		{1, 1, 1},
// 		{-1, 1, 1},
// 		// back
// 		{-1, -1, -1},
// 		{1, -1, -1},
// 		{1, 1, -1},
// 		{-1, 1, -1},
// 	};
//
// 	// Structure representing a triangular face
// 	struct Face
// 	{
// 		GLuint v0, v1, v2;
// 	};
//
// 	// Indices define triangles that index into vertices
// 	// Define cube indices
// 	std::vector<Face> indices = {
// 		// front
// 		{0, 1, 2},
// 		{2, 3, 0},
// 		// right
// 		{1, 5, 6},
// 		{6, 2, 1},
// 		// back
// 		{7, 6, 5},
// 		{5, 4, 7},
// 		// left
// 		{4, 0, 3},
// 		{3, 7, 4},
// 		// bikini bottom
// 		{4, 5, 1},
// 		{1, 0, 4},
// 		// top
// 		{3, 2, 6},
// 		{6, 7, 3},
// 	};
//
// 	// Program to associate with the object
// 	std::unique_ptr<ppgso::Shader> shader;
//
// 	// These will hold the data and object buffers
// 	GLuint vao, vbo, cbo, ibo;
// 	glm::mat4 modelMatrix{1.0f};
// 	glm::mat4 viewMatrix{1.0f};
//
// public:
// 	// Public attributes that define position, color ..
// 	glm::vec3 position;
// 	glm::vec3 rotation{0, 0, 0};
// 	glm::vec3 scale;
// 	glm::vec3 color;
//
//     int drawable;
//
// 	// Initialize object data buffers
// 	Cube(glm::vec3 pos, glm::vec3 scl, int draw)
// 	{
// 		position = pos;
// 		scale = scl;
//
//         drawable = draw;
//
// 		//shader
// 		if (!shader)
// 			shader = std::make_unique<ppgso::Shader>(color_vert_glsl, color_frag_glsl);
//
// 		// Copy data to OpenGL
// 		glGenVertexArrays(1, &vao);
// 		glBindVertexArray(vao);
//
// 		// Copy positions to gpu
// 		glGenBuffers(1, &vbo);
// 		glBindBuffer(GL_ARRAY_BUFFER, vbo);
// 		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
//
// 		// Set vertex program inputs
// 		auto position_attrib = shader->getAttribLocation("Position");
// 		glEnableVertexAttribArray(position_attrib);
// 		glVertexAttribPointer(position_attrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
//
// 		// Copy indices to gpu
// 		glGenBuffers(1, &ibo);
// 		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
// 		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Face), indices.data(), GL_STATIC_DRAW);
// 	};
// 	// Clean up
// 	~Cube()
// 	{
// 		// Delete data from OpenGL
// 		glDeleteBuffers(1, &ibo);
// 		glDeleteBuffers(1, &cbo);
// 		glDeleteBuffers(1, &vbo);
// 		glDeleteVertexArrays(1, &vao);
// 	}
//
// 	bool update(float dTime, Scene &scene) override
// 	{
// 		modelMatrix = glm::mat4(1.0f);
// 		modelMatrix = glm::translate(modelMatrix, position);
// 		modelMatrix = glm::scale(modelMatrix, scale);
//
// 		return true;
// 	}
//
// 	// Draw polygons
// 	void render(Scene &scene) override
// 	{
// 		//update viewMatrix
// 		viewMatrix = scene.camera->viewMatrix;
//
// 		// Update transformation and color uniforms in the shader
// 		shader->use();
// 		shader->setUniform("OverallColor", color);
// 		shader->setUniform("ModelMatrix", modelMatrix);
// 		shader->setUniform("ViewMatrix", viewMatrix);
// 		shader->setUniform("ProjectionMatrix",scene.camera->perspective);
//
// 		glBindVertexArray(vao);
//         if (drawable == 1)
// 		    glDrawElements(GL_TRIANGLES, (GLsizei)indices.size() * 3, GL_UNSIGNED_INT, 0);
// 	};
// };
//
//
// #endif
