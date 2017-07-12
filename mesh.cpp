#include "mesh.hpp"

Mesh Mesh::createSphere(float radius, int resolution)
{
	Mesh mesh;

	for (float i(0); i < resolution + 1; ++i)
	{

		float tr(sin(M_PI - i * M_PI / resolution));
		float ny(cos(M_PI - i * M_PI / resolution));

		for (float j(0); j <= resolution * 2; ++j)
		{
			float nx(tr * sin(j * M_PI / resolution));
			float nz(tr * cos(j * M_PI / resolution));

			Vector3f vertex(nx, ny, nz);
			mesh.addNormal(vertex);
			mesh.addVertex(vertex * radius);
		}
	}

	for (int y(0); y < resolution; ++y)
	{
		for (int x(0); x <= resolution * 2; ++x)
		{
			mesh.addIndex((y) * (resolution * 2 + 1) + x);
			mesh.addIndex((y + 1) * (resolution * 2 + 1) + x);
		}
	}

	return mesh;
}

Mesh::Mesh() : vbos(3)
{
	glGenBuffers(vbos.size(), vbos.data());
}

Mesh::~Mesh()
{
	glDeleteBuffers(vbos.size(), vbos.data());
}

void Mesh::update()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vector3f), vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Vector3f), normals.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(IndexType), indices.data(), GL_STATIC_DRAW);
}

void Mesh::draw() const
{
	glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbos[1]);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[2]);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, 0);

	glDisableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, 0);

	glDrawElements(GL_TRIANGLE_STRIP, indices.size(), GL_UNSIGNED_INT, 0);

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::append(const Mesh& mesh)
{
	auto offset(indices.back());

	transform(begin(mesh.getIndices()), end(mesh.getIndices()), back_inserter(indices), [&](auto index)
	{
		return index + offset;
	});

	vertices.insert(end(vertices), begin(mesh.getVertices()), end(mesh.getVertices()));
	normals.insert(end(normals), begin(mesh.getNormals()), end(mesh.getNormals()));
}

void Mesh::append(Mesh&& mesh)
{
	auto offset(indices.back());

	transform(begin(mesh.getIndices()), end(mesh.getIndices()), back_inserter(indices), [&](auto index)
	{
		return index + offset;
	});

	vertices.insert(end(vertices), make_move_iterator(begin(mesh.getVertices())), make_move_iterator(end(mesh.getVertices())));
	normals.insert(end(normals), make_move_iterator(begin(mesh.getNormals())), make_move_iterator(end(mesh.getNormals())));
}

vector<Vector3f, aligned_allocator<Vector3f>>& Mesh::getVertices()
{
	return vertices;
}

const vector<Vector3f, aligned_allocator<Vector3f>>& Mesh::getVertices() const
{
	return vertices;
}

vector<Vector3f, aligned_allocator<Vector3f>>& Mesh::getNormals()
{
	return normals;
}

const vector<Vector3f, aligned_allocator<Vector3f>>& Mesh::getNormals() const
{
	return normals;
}

vector<IndexType>& Mesh::getIndices()
{
	return indices;
}

const vector<IndexType>& Mesh::getIndices() const
{
	return indices;
}

Vector3f Mesh::getVertex(size_t idx) const
{
	return vertices.at(idx);
}

void Mesh::setVertex(size_t idx, const Vector3f& vertex)
{
	vertices.at(idx) = vertex;
}

void Mesh::setVertex(size_t idx, Vector3f&& vertex)
{
	vertices.at(idx) = move(vertex);
}

Vector3f Mesh::getNormal(size_t idx) const
{
	return normals.at(idx);
}

void Mesh::setNormal(size_t idx, const Vector3f& normal)
{
	normals.at(idx) = normal;
}

void Mesh::setNormal(size_t idx, Vector3f&& normal)
{
	normals.at(idx) = move(normal);
}

IndexType Mesh::getIndex(size_t idx) const
{
	return indices.at(idx);
}

void Mesh::setVertex(size_t idx, IndexType index)
{
	indices.at(idx) = index;
}

void Mesh::addVertex(const Vector3f& vertex)
{
	vertices.push_back(vertex);
}

void Mesh::addVertex(Vector3f&& vertex)
{
	vertices.push_back(move(vertex));
}

void Mesh::addVertices(const vector<Vector3f, aligned_allocator<Vector3f>>& verts)
{
	vertices.insert(end(vertices), begin(verts), end(verts));
}

void Mesh::addVertices(vector<Vector3f, aligned_allocator<Vector3f>>&& verts)
{
	vertices.insert(end(vertices), make_move_iterator(begin(verts)), make_move_iterator(end(verts)));
}

void Mesh::addNormal(const Vector3f& normal)
{
	normals.push_back(normal);
}

void Mesh::addNormal(Vector3f&& normal)
{
	normals.push_back(move(normal));
}

void Mesh::addNormals(const vector<Vector3f, aligned_allocator<Vector3f>>& norms)
{
	normals.insert(end(normals), begin(norms), end(norms));
}

void Mesh::addNormals(vector<Vector3f, aligned_allocator<Vector3f>>&& norms)
{
	normals.insert(end(normals), make_move_iterator(begin(norms)), make_move_iterator(end(norms)));
}

void Mesh::addIndex(IndexType index)
{
	indices.push_back(index);
}

void Mesh::addIndices(const vector<IndexType>& idxs)
{
	indices.insert(end(indices), begin(idxs), end(idxs));
}

void Mesh::addIndices(vector<IndexType>&& idxs)
{
	indices.insert(end(indices), make_move_iterator(begin(idxs)), make_move_iterator(end(idxs)));
}

void Mesh::clearVertices()
{
	vertices.clear();
}
void Mesh::clearNormals()
{
	normals.clear();
}

void Mesh::clearIndices()
{
	indices.clear();
}

void Mesh::clear()
{
	clearVertices();
	clearNormals();
	clearIndices();
}