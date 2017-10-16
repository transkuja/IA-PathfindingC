/***************************************************/
/* Nom:	Math.h
/* Description: Math
/* Auteur: BRUNEAU Colin
/***************************************************/
#ifndef _Math_H
#define _Math_H

namespace crea
{
#define PI 3.14159265f
#define EPSILON 0.00001f
#define ONEOVER128 0.0078125f

	class CREAENGINE_API Vector2f
	{
		float m_fX;
		float m_fY;
	public:

		Vector2f()
		{
			m_fX = 0.f;
			m_fY = 0.f;
		}

		Vector2f(float _fX, float _fY)
		{
			m_fX = _fX;
			m_fY = _fY;
		}

		~Vector2f()
		{
		}

		inline void setX(float _fX) { m_fX = _fX; }
		inline void setY(float _fY) { m_fY = _fY; }
		inline float getX() { return m_fX; }
		inline float getY() { return m_fY; }
		inline float get(char _index) { return (_index==0? m_fX : m_fY); }
		inline void addX(float _fX) { m_fX += _fX; }
		inline void addY(float _fY) { m_fY += _fY; }
		inline float dist(Vector2f& _v) { return sqrt((_v.m_fX - m_fX) * (_v.m_fX - m_fX) + (_v.m_fY - m_fY) * (_v.m_fY - m_fY)); }
		inline float distSq(Vector2f& _v) { return ((_v.m_fX - m_fX) * (_v.m_fX - m_fX) + (_v.m_fY - m_fY) * (_v.m_fY - m_fY)); }
		inline float length() const { return sqrt((m_fX * m_fX) + (m_fY * m_fY)); }
		inline float lengthSq() const { return (m_fX * m_fX) + (m_fY * m_fY); }
		inline bool normalize() { float l = length();  if (!l) return false; m_fX /= l; m_fY /= l; return true; }
		inline float dot(const Vector2f& _v) const {	return m_fX * _v.m_fX + m_fY * _v.m_fY;	}
		inline float angle(const Vector2f& _v) const { float fLength = length() * _v.length(); return acosf(dot(_v) / fLength);	} // radians
		bool isLeft(const Vector2f& _v) const { return (bool)((m_fX*_v.m_fY - m_fY*_v.m_fX) > 0.0f); }
		inline Vector2f operator-() { return Vector2f(-m_fX, -m_fY); }
		inline Vector2f operator+(Vector2f& _v) { return Vector2f(m_fX + _v.m_fX, m_fY + _v.m_fY); }
		inline Vector2f operator-(Vector2f& _v) { return Vector2f(m_fX - _v.m_fX, m_fY - _v.m_fY); }
		inline Vector2f& operator+=(Vector2f& _v) { m_fX += _v.m_fX; m_fY += _v.m_fY; return *this; }
		inline Vector2f& operator-=(Vector2f& _v) { m_fX -= _v.m_fX; m_fY -= _v.m_fY; return *this; }
		inline Vector2f operator*(float _f) { return Vector2f(m_fX * _f, m_fY * _f); }
		inline Vector2f& operator*=(float _f) { m_fX *= _f; m_fY *= _f; return *this; }
		inline Vector2f operator/(float _f) { assert(_f); return Vector2f(m_fX / _f, m_fY / _f); }
		inline Vector2f& operator/=(float _f) { assert(_f); m_fX /= _f; m_fY /= _f; return *this; }
	};

	class CREAENGINE_API IntRect
	{
		int m_iX;
		int m_iY;
		int m_iW;
		int m_iH;

	public:

		IntRect()
		{
			m_iX = 0;
			m_iY = 0;
			m_iW = 0;
			m_iH = 0;
		}

		IntRect(int _x, int _y, int _w, int _h)
		{
			m_iX = _x;
			m_iY = _y;
			m_iW = _w;
			m_iH = _h;
		}

		~IntRect()
		{
		}

		inline int getLeft() const { return m_iX; }
		inline int getTop() const { return m_iY; }
		inline int getWidth() const { return m_iW; }
		inline int getHeight() const { return m_iH; }

	};

	class CREAENGINE_API FloatRect
	{
		float m_fX;
		float m_fY;
		float m_fW;
		float m_fH;
	public:

		FloatRect()
		{
		}

		FloatRect(float _x, float _y, float _w, float _h)
		{
			m_fX = _x;
			m_fY = _y;
			m_fW = _w;
			m_fH = _h;
		}

		~FloatRect()
		{
		}

		FloatRect(Vector2f _vStart, Vector2f _vEnd)
		{
			float x1 = _vStart.getX();
			float y1 = _vStart.getY();
			float x2 = _vEnd.getX();
			float y2 = _vEnd.getY();
			m_fX = x1;
			m_fY = y1;
			m_fW = x2 - x1;
			m_fH = y2 - y1;
			if (m_fW < 0.f)
			{
				m_fX = x2;
				m_fW = -m_fW;
			}
			if (m_fH < 0.f)
			{
				m_fY = y2;
				m_fH = -m_fH;
			}

		}

		bool contains(Vector2f& _v)
		{
			if (_v.getX() > m_fX && _v.getX() < m_fX + m_fW && _v.getY() > m_fY && _v.getY() < m_fY + m_fH)
			{
				return true;
			}
			return false;
		}

	};

	class CREAENGINE_API MathTools
	{
	public:

		static Vector2f truncate(Vector2f _vector, float lengthLimit) {
			float length = _vector.length();
			if (length > lengthLimit) {
				_vector.normalize();
				return _vector * lengthLimit;
			}
			else return _vector;
		}

		static bool zeroByEpsilon(float _value) { return _value > -EPSILON && _value < EPSILON; }

		static float lerp(float a, float b, float f) { return a * (1 - f) + b * f; }

		static float degreetoradian(float a) { return a * 0.01745329251945f; }

		static float radiantodegreee(float a) { return a * 57.29577951471995f; }

		//static float min(float a, float b) { return a < b ? a : b; }

		//static float max(float a, float b) { return a > b ? a : b; }

	};

} // namespace crea

#endif // _ICore_H