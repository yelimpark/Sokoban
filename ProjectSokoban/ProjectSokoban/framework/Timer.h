#pragma once

/// <summary>
/// 타이머를 초기화 한다.
/// </summary>
void InitializeTimer();

/// <summary>
/// 타이머를 최신화한다.
/// </summary>
void UpdateTimer();

/// <summary>
/// 델타 타임 (프레임간 시간)을 구한다.
/// </summary>
float GetDeltaTime();