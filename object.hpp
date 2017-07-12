#pragma once

#include "mesh.hpp"
#include "material.hpp"
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/StdVector>

using namespace std;
using namespace Eigen;

/*
	��ʓI�ȃI�u�W�F�N�g��\���N���X
*/
class Object
{

protected:

	// �ʒu
	Vector3f position;

	// ���x
	Vector3f velocity;

	// �����x
	Vector3f acceleration;

	// �}�e���A��
	Material material;

	// ���_�A�@���A�C���f�b�N�X���i�[���Ă���N���X
	// �`��͂��ׂĂ����ɔC����
	Mesh mesh;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	Object() = default;
	virtual ~Object() = default;

	Object(const Object&) = default;
	Object(Object&&) = default;

	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;

	// �ʒu���X�V
	void update();

	// ���_���W��`��
	virtual void draw() const;

	// �Փ˔���(?)
	bool colliding(const Object&);
	
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

	Mesh& getMesh();
	const Mesh& getMesh() const;
};