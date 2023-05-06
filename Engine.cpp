#include "Engine.h"
#include <iostream>
using namespace std;


Engine* Engine::s_Instance = nullptr;

// Hàm khởi tạo
Engine::Engine() :
	m_isRunning(false)
{

}

// Hàm hủy
Engine::~Engine()
{

}

// Phương thức GetInstance


bool Engine::Init()
{
	m_isRunning = true;
	return m_isRunning;
}

bool Engine::Clean()
{
	return false;
}

void Engine::Quit()
{

}

void Engine::Update()
{
	cout << "Updating ......" << endl;
}

void Engine::Render()
{
}

void Engine::Events()
{
}
