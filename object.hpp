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
	一般的なオブジェクトを表すクラス
*/
class Object
{

protected:

	// 位置
	Vector3f position;

	// 速度
	Vector3f velocity;

	// 加速度
	Vector3f acceleration;

	// マテリアル
	Material material;

	// 頂点、法線、インデックスを格納しているクラス
	// 描画はすべてここに任せる
	Mesh mesh;

public:

	EIGEN_MAKE_ALIGNED_OPERATOR_NEW

	Object() = default;
	virtual ~Object() = default;

	Object(const Object&) = default;
	Object(Object&&) = default;

	Object& operator=(const Object&) = default;
	Object& operator=(Object&&) = default;

	// 位置を更新
	void update();

	// 頂点座標を描画
	virtual void draw() const;

	// 衝突判定(?)
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