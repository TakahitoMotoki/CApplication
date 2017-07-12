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
	�`���S�ĒS���N���X
	���_�A�@���A�C���f�b�N�X���i�[���Ă���
*/
class Mesh
{
public:

	// ����\�����b�V����Ԃ�
	static Mesh createSphere(float, int);

private:

	// ���_�o�b�t�@�I�u�W�F�N�g(VBO)
	vector<GLuint> vbos;
	// ���_
	vector<Vector3f, aligned_allocator<Vector3f>> vertices;
	// �@��
	vector<Vector3f, aligned_allocator<Vector3f>> normals;
	// �C���f�b�N�X
	vector<IndexType> indices;

public:

	Mesh();
	~Mesh();

	Mesh(const Mesh&) = default;
	Mesh(Mesh&&) = default;

	Mesh& operator=(const Mesh&) = default;
	Mesh& operator=(Mesh&&) = default;

	// ���_�A�@���A�C���f�b�N�X��ύX�����炱�̊֐����Ă�ŁAGL�ɔ��f
	void update();
	// �`��
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
