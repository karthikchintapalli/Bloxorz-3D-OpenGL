#version 330 core

// Interpolated values from the vertex shaders
in vec3 fragColor;
in vec3 Normal;
in vec3 FragPos;

uniform vec3 lightPos1;
uniform vec3 lightPos2;
//uniform vec3 lightPos3;

// output data
out vec4 color;

void main()
{
    // Output color = color specified in the vertex shader,
    // interpolated between all 3 surrounding vertices of the triangle

    vec3 norm = normalize(Normal);
	//vec3 lightDir1 = normalize(vec3(-70.0, 100.0, 70.0) - FragPos);
	//float diff1 = max(dot(norm, lightDir1), 0.0);
	//vec3 diffuse1 = diff1 * vec3(1.0, 1.0, 1.0);

	vec3 lightDir2 = normalize(vec3(70.0, 100.0, 70.0) - FragPos);
	float diff2 = max(dot(norm, lightDir2), 0.0);
	vec3 diffuse2 = diff2 * vec3(1.0, 1.0, 1.0);
	
	vec3 result = (vec3(0.1, 0.1, 0.1) + diffuse2 * 1.0) * fragColor;
	color = vec4(result, 1.0);

    //color = fragColor;
}
