#pragma once

#include <GLUT/glut.h>
#include <vector>
#include <array>
#include <iostream>
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include "material.hpp"

using namespace std;
using namespace Eigen;

// ��ʓI�ȃI�u�W�F�N�g�̃N���X
class Object
{
protected:

	// �ʒu
	Vector3f position;
	// ����
	Vector3f orientation;
	// ���x
	Vector3f velocity;
	// �����x
	Vector3f acceleration;

	// �}�e���A��
	Material material;

	// ���_���W
	vector<Vector3f, aligned_allocator<Vector3f>> vertices;

public:

	virtual ~Object() = default;

	// �����ݒ�
	void setup();

	// �ʒu��������X�V
	void update();

	// ���_���W��`��
	virtual void draw() const;

	// �Փ˔���
	bool colliding(const Object&);

	vector<Vector3f, aligned_allocator<Vector3f>>& getVertices();
	const vector<Vector3f, aligned_allocator<Vector3f>>& getVertices() const;
	
	Vector3f getPosition() const;
	void setPosition(const Vector3f&);
	void setPosition(Vector3f&&);

	Vector3f getOrientation() const;
	void setOrientation(const Vector3f&);
	void setOrientation(Vector3f&&);

	Vector3f getVelocity() const;
	void setVelocity(const Vector3f&);
	void setVelocity(Vector3f&&);

	Vector3f getAcceleration() const;
	void setAcceleration(const Vector3f&);
	void setAcceleration(Vector3f&&);

	Material getMaterial() const;
	void setMaterial(const Material&);
	void setMaterial(Material&&);
};

// ���P�b�g�N���X
class Rocket : public Object
{
public:

	void draw() const override
	{
		material.begin();

		glPushMatrix();
		{
			glTranslatef(position.x(), position.y(), position.z());

			// �����Ƀ��P�b�g�`��̃R�[�h������
			// ...
		}
		glPopMatrix();
	}
};

// 覐΃N���X
class Meteorite : public Object
{
public:

	void draw() const override
	{
		material.begin();

		glPushMatrix();
		{
			glTranslatef(position.x(), position.y(), position.z());

			// ������覐Ε`��̃R�[�h������
			// �Ƃ肠�����͋���
			glutSolidSphere(0.5, 30, 30);
		}
		glPopMatrix();
	}
};
