#include "Configuration.h"
class Step_Motor_Group
{
private:
	//parameters
	// Use the next two Bool variables to change the default Step Motor dir.
	// true is forward direction, false is reverse direction.
	int m_step_motor1_initialize_dir;
	int m_step_motor1_work_dir;
	int m_step_motor2_initialize_dir;
	int m_step_motor2_work_dir;
	// Use the next two __int64 variables to set the loop times for the two Step Motor.
	// In Full step, 42 Step Motor rotate a circle need 200 pulses, because each pulse provide 1.8бу rotation.
	int64_t m_step_motor1_loop_times;
	int64_t m_step_motor2_loop_times;
	// Use the next four Integer variables to control the High pulses and the low pulses.
	int m_step_motor1_high_delayms;
	int m_step_motor1_low_delayms;
	int m_step_motor2_high_delayms;
	int m_step_motor2_low_delayms;
	// methods
	void Step_Motor_Open_Enable();
	void Step_Motor_Close_Enable();
public:
	// Stop in the Work function, controlled by UI Screen.
	void Initialize_Step_Motor();	// Used when we open the machine or Reset the Step Motors' positions.
	void Step_Motor_Work();	// Used when the Step Motors work.
	void Reset_Step_Motor();
	Step_Motor_Group(const int initialize_dir1 = Step_Motor1_Initialize_Dir,
		const int work_dir1 = Step_Motor1_Work_Dir,
		const int initialize_dir2 = Step_Motor2_Initialize_Dir,
		const int work_dir2= Step_Motor2_Work_Dir,
		const int64_t loop1=Step_Motor1_Loop_Times,
		const int64_t loop2 =Step_Motor2_Loop_Times,
		const int high1_delayms=Step_Motor1_HIGH_Delayms,
		const int low1_delayms =Step_Motor1_LOW_Delayms,
		const int high2_delayms = Step_Motor2_HIGH_Delayms,
		const int low2_delayms = Step_Motor2_LOW_Delayms);	// The default constructor

};