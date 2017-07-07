#pragma once

#include <GL/glut.h>
#include <vector>
#include <array>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/StdVector>

using namespace std;

class Object
{
private:

	// �ʒu��3�������W
	array<float, 3> position;
	// ����(�܂��l����)
	array<float, 3> orientation;

	// �}�e���A���̐F
	array<float, 4> materialDiffuseColor;
	array<float, 4> materialAmbientColor;
	array<float, 4> materialSpecularColor;
	float materialShininess;

	// �`�悷��ۂ̒��_���W���i�[���Ă���vector
	vector<array<float, 3>> vertices;

public:

	Object();

	~Object();

	Object(const Object& object);

	Object(Object&& object);

	Object& operator=(const Object& object);

	Object& operator=(Object&& object);

	// �K�v�ɉ����ď����ݒ�
	void setup();

	// �ʒu��������X�V
	void update();

	// ���_���W��`��
	void draw() const;

	// �ʒu���Q�b�g
	array<float, 3> getPosition() const;

	// �ʒu���Z�b�g
	void setPosition(const array<float, 3>& _position);

	void setPosition(array<float, 3>&& _position);

	// �������Q�b�g
	array<float, 3> getOrientation() const;

	// �������Z�b�g
	void setOrientation(const array<float, 3>& _orientation);

	void setOrientation(array<float, 3>&& _orientation);
};
