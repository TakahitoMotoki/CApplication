#pragma once

#define _USE_MATH_DEFINES

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <cmath>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/StdVector>

using namespace std;
using namespace Eigen;

using IndexType = unsigned int;

/*
	描画を全て担うクラス
	頂点、法線、インデックスを格納している
*/
class Mesh
{
public:

	// 球を表すメッシュを返す
	static Mesh createSphere(float, int);

private:

	// 頂点バッファオブジェクト(VBO)
	vector<GLuint> vbos;
	// 頂点
	vector<Vector3f, aligned_allocator<Vector3f>> vertices;
	// 法線
	vector<Vector3f, aligned_allocator<Vector3f>> normals;
	// インデックス
	vector<IndexType> indices;

public:

	Mesh();
	~Mesh();

	Mesh(const Mesh&) = default;
	Mesh(Mesh&&) = default;

	Mesh& operator=(const Mesh&) = default;
	Mesh& operator=(Mesh&&) = default;

	// 頂点、法線、インデックスを変更したらこの関数を呼んで、GLに反映
	void update();
	// 描画
	void draw() const;

	void append(const Mesh&);
	void append(Mesh&&);

	vector<Vector3f, aligned_allocator<Vector3f>>& getVertices();
	const vector<Vector3f, aligned_allocator<Vector3f>>& getVertices() const;

	vector<Vector3f, aligned_allocator<Vector3f>>& getNormals();
	const vector<Vector3f, aligned_allocator<Vector3f>>& getNormals() const;

	vector<IndexType>& getIndices();
	const vector<IndexType>& getIndices() const;

	Vector3f getVertex(size_t) const;
	void setVertex(size_t, const Vector3f&);
	void setVertex(size_t, Vector3f&&);

	Vector3f getNormal(size_t) const;
	void setNormal(size_t, const Vector3f&);
	void setNormal(size_t, Vector3f&&);

	IndexType getIndex(size_t) const;
	void setVertex(size_t, IndexType);

	void addVertex(const Vector3f&);
	void addVertex(Vector3f&&);

	void addVertices(const vector<Vector3f, aligned_allocator<Vector3f>>&);
	void addVertices(vector<Vector3f, aligned_allocator<Vector3f>>&&);

	void addNormal(const Vector3f&);
	void addNormal(Vector3f&&);

	void addNormals(const vector<Vector3f, aligned_allocator<Vector3f>>&);
	void addNormals(vector<Vector3f, aligned_allocator<Vector3f>>&&);

	void addIndex(IndexType);
	void addIndices(const vector<IndexType>&);
	void addIndices(vector<IndexType>&&);

	void clearVertices();
	void clearNormals();
	void clearIndices();
	void clear();
};
