#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_lineFloor = make_shared<Line>(Vector2(0,500), Vector2(1000,330)); // 검은색선, 3
	_lineMouse = make_shared<Line>(Vector2(50, 250), Vector2(50, 250)); // 파란색선, 3
	_lineShadow = make_shared <Line>(Vector2(50, 450), Vector2(60, 450)); // 빨간선, 3
}

LineScene::~LineScene()
{

}

void LineScene::Update()
{
	_lineMouse->_end = mousePos;
	// _lineShadow->_start = ? 
	// _lineShadow-> end_x = _lineMouse -> _end.x;

	Vector2 line_mouseVec = _lineMouse->GetVector2();
	Vector2 line_floorVec = _lineFloor->GetVector2();
	Vector2 floor_Normal = line_floorVec.NormalVector2();
	float shadowLength = line_mouseVec.Dot(floor_Normal);

	_lineShadow->_end = _lineShadow->_start + floor_Normal * shadowLength;
	
	float aLean = -(line_floorVec.x / line_floorVec.y);
	float bLean = _lineShadow->_start.x / _lineShadow->_start.y;

	float cX = _lineShadow->_start.x;
	float cY = _lineShadow->_start.y;

	float a = ((-(aLean * _lineMouse->_start.x) + _lineMouse->_start.y) - ((-(bLean * cX) + cY))) / (bLean - aLean);
	float b = aLean * (a - _lineMouse->_start.x) + _lineMouse->_start.y;

	_lineShadow->_start.x = a;
	_lineShadow->_start.y = b;

	_lineFloor->Update();
	_lineMouse->Update();
	_lineShadow->Update();
}

void LineScene::Render(HDC hdc)
{
	_lineFloor->Render(hdc);
	_lineMouse->Render(hdc);
	_lineShadow->Render(hdc);
}
