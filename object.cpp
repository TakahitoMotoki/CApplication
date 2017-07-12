#include "object.hpp"

void Object::update()
{
	// 等加速度運動を仮定して位置更新
	position += velocity + acceleration * 0.5;
	velocity += acceleration;
}

void Object::draw() const
{
	// マテリアルを反映
	material.begin();

	glPushMatrix();
	{
		// 自分の位置に座標系を平行移動
		glTranslatef(position.x(), position.y(), position.z());

		// 頂点座標を描画
		// mesh.draw();

		glutSolidSphere(0.5, 30, 30);

		// 以下のようにすると遅い

		/*

		glBegin(GL_TRIANGLES);
		{
			for_each(begin(vertices), end(vertices), [](const auto& vertex)
			{
				glVertex3fv(vertex.data());
			});
		}
		glEnd();

		*/
	}
	glPopMatrix();
}

bool Object::colliding(const Object& object)
{
	// 衝突判定のコードをかく
	// ...

	return true;
}

Vector3f Object::getPosition() const
{
	return position;
}

void Object::setPosition(const Vector3f& _position)
{
	position = _position;
}

void Object::setPosition(Vector3f&& _position)
{
	position = move(_position);
}

Vector3f Object::getVelocity() const
{
	return velocity;
}

void Object::setVelocity(const Vector3f& _velocity)
{
	velocity = _velocity;
}

void Object::setVelocity(Vector3f&& _velocity)
{
	velocity = move(_velocity);
}

Vector3f Object::getAcceleration() const
{
	return acceleration;
}

void Object::setAcceleration(const Vector3f& _acceleration)
{
	acceleration = _acceleration;
}

void Object::setAcceleration(Vector3f&& _acceleration)
{
	acceleration = move(_acceleration);
}

Material Object::getMaterial() const
{
	return material;
}

void Object::setMaterial(const Material& _material)
{
	material = _material;
}

void Object::setMaterial(Material&& _material)
{
	material = move(_material);
}

Mesh& Object::getMesh()
{
	return mesh;
}

const Mesh& Object::getMesh() const
{
	return mesh;
}