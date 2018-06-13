void CalcRefVec( void )
{ 
    if( Vr1 >= 0 )
        {       
        // (xx1)
        if( Vr2 >= 0 )
            {
            // (x11)
            // Must be Sector 3 since Sector 7 not allowed
            // Sector 3: (0,1,1)  0-60 degrees
            T1 = Vr2
            T2 = Vr1
            CalcTimes();
            dPWM1 = Ta
            dPWM2 = Tb
            dPWM3 = Tc
            }
        else
            {            
            // (x01)
            if( Vr3 >= 0 )
                {
                // Sector 5: (1,0,1)  120-180 degrees
                T1 = Vr1
                T2 = Vr3
                CalcTimes();
                dPWM1 = Tc
                dPWM2 = Ta
                dPWM3 = Tb

                }
            else
                {
                // Sector 1: (0,0,1)  60-120 degrees
                T1 = -Vr2
                T2 = -Vr3
                CalcTimes();
                dPWM1 = Tb
                dPWM2 = Ta
                dPWM3 = Tc
                }
            }
        }
    else
        {
        // (xx0)
        if( Vr2 >= 0 )
            {
            // (x10)
            if( Vr3 >= 0 )
                {
                // Sector 6: (1,1,0)  240-300 degrees
                T1 = Vr3
                T2 = Vr2
                CalcTimes();
                dPWM1 = Tb
                dPWM2 = Tc
                dPWM3 = Ta
                }
            else
                {
                // Sector 2: (0,1,0)  300-0 degrees
                T1 = -Vr3
                T2 = -Vr1
                CalcTimes();
                dPWM1 = Ta
                dPWM2 = Tc
                dPWM3 = Tb
                }
            }
        else
            {            
            // (x00)
            // Must be Sector 4 since Sector 0 not allowed
            // Sector 4: (1,0,0)  180-240 degrees
            T1 = -Vr1
            T2 = -Vr2
            CalcTimes();
            dPWM1 = Tc
            dPWM2 = Tb
            dPWM3 = Ta

            }
        }
}


void CalcTimes(void)
{
    T1 = PWM*T1
    T2 = PWM*T2
    Tc = (PWM-T1-T2)/2
    Tb = Ta + T1
    Ta = Tb + T2
}        
