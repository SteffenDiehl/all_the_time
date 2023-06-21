void Rotary_Click(int *m, int *p, int *b, int *Wi_Fi, int *Web_Server, int *act_t, unsigned long *t1, unsigned long *t2, unsigned long *t3, unsigned long *t4, unsigned long *t5,unsigned long *fix_timer, unsigned long *t, int wi_fi, int *t_anz, int *t_pause, int *t_out){
    switch(*m){
        case 1://kein Timer aktiv
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 7;
                *p = 1;

                break;

            case 2:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 2://ein Timer aktiv
            
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 11;
                *p = 1;
                *t_anz = 1;

                break;

            case 2:
                *b = *m;
                *m = 7;
                *p = 1;

                break;

            case 3:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;
        
        case 3://zwei Timer aktiv
            
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 11;
                *p = 1;
                *t_anz = 1;

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;
                *t_anz = 2;

                break;

            case 3:
                *b = *m;
                *m = 7;
                *p = 1;

                break;

            case 4:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 4://drei Timer aktiv
            
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 11;
                *p = 1;
                *t_anz = 1;

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;
                *t_anz = 2;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;
                *t_anz = 3;

                break;

            case 4:
                *b = *m;
                *m = 7;
                *p = 1;

                break;

            case 5:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 5://vier Timer aktiv
            
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 11;
                *p = 1;
                *t_anz = 1;

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;
                *t_anz = 2;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;
                *t_anz = 3;

                break;

            case 4:
                *b = *m;
                *m = 14;
                *p = 1;
                *t_anz = 4;

                break;

            case 5:
                *b = *m;
                *m = 7;
                *p = 1;

                break;

            case 6:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 6://fünf Timer aktiv
            
            switch (*p)
            {
            case 1:
                *b = *m;
                *m = 11;
                *p = 1;
                *t_anz = 1;

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;
                *t_anz = 2;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;
                *t_anz = 3;

                break;

            case 4:
                *b = *m;
                *m = 14;
                *p = 1;
                *t_anz = 4;

                break;

            case 5:
                *b = *m;
                *m = 15;
                *p = 1;
                *t_anz = 5;

                break;

            case 6:
                *b = *m;
                *m = 10;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;
    	
        case 7://new Timer
            
            switch(*p)
            {
            case 1:
                *m = 8;
                *p = 1;

                break;

            case 2:
                *m = 9;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 8:
            act_t++;
            switch (*act_t)
            {
            case 1:
                t[0] = *t1;
                *m = 2;
                *p = 1;
                break;

            case 2:
                t[1] = *t2;
                *m = 3;
                *p = 1;
                break;

            case 3:
                t[2] = *t3;
                *m = 4;
                *p = 1;
                break;

            case 4:
                t[3] = *t4;
                *m = 5;
                *p = 1;
                break;

            case 5:
                t[4] = *t5;
                *m = 6;
                *p = 1;
                break;
            
            default:
                break;
            }

            break;

        case 9://feste Timer
            act_t++;
            switch (*act_t)
            {
            case 1:
                switch (*p)
                {
                case 1:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 2:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 3:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 4:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 5:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 6:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 7:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 8:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 9:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;

                case 10:
                    *t1 = fix_timer[(*p-1)];
                    t[0] = *t1;
                    *m = 2;
                    *p = 1;
                    
                    break;
                
                default:
                    break;
                }
                
                break;

            case 2:
                switch (*p)
                {
                case 1:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 2:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 3:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 4:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 5:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 6:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 7:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 8:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 9:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;

                case 10:
                    *t1 = fix_timer[(*p-1)];
                    t[1] = *t2;
                    *m = 3;
                    *p = 1;
                    
                    break;
                
                default:
                    break;
                }
                
                break;

            case 3:
                switch (*p)
                {
                case 1:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 2:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 3:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 4:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 5:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 6:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 7:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 8:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 9:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;

                case 10:
                    *t1 = fix_timer[(*p-1)];
                    t[2] = *t3;
                    *m = 4;
                    *p = 1;
                    
                    break;
                
                default:
                    break;
                }
                
                break;

            case 4:
                switch (*p)
                {
                case 1:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 2:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 3:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 4:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 5:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 6:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 7:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 8:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 9:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;

                case 10:
                    *t1 = fix_timer[(*p-1)];
                    t[3] = *t4;
                    *m = 5;
                    *p = 1;
                    
                    break;
                
                default:
                    break;
                }
                
                break;

            case 5:
                switch (*p)
                {
                case 1:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 2:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 3:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 4:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 5:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 6:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 7:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 8:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 9:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;

                case 10:
                    *t1 = fix_timer[(*p-1)];
                    t[4] = *t5;
                    *m = 6;
                    *p = 1;
                    
                    break;
                
                default:
                    break;
                }
                
                break;
            
            default:
                break;
            }
            
            break;

        case 10://Wifi Setup
            switch (*p)
            {
            case 1:
                if(*Wi_Fi == 0){
                    *Wi_Fi = 1;
                }

                else{
                    *Wi_Fi = 0;
                }

                break;

            case 2:
                if(*Web_Server == 0 && wi_fi){
                    *Web_Server = 1;
                }

                else{
                    *Web_Server = 0;
                }

                break;
            
            case 3:
                *m = *b;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;
        
        case 11://Timer 1
            switch (*p)
            {
            case 2:
                if(t_pause[0]){
                    t_pause[0] = 0;
                }
                else{
                    t_pause[0] = 1;
                }

                break;

            case 3:
                *act_t--;
                switch (*act_t)
                {
                case 0:
                    *t1 = 0;
                    *m = 1;
                    *p = 1;
                    break;
                    
                case 1:
                    if(t[0] == 0){
                        *t1 = *t2;
                        t[0] = t[1];
                    }
                    *t2 = 0;
                    t[1] = 0;
                    if(*t_out == 0){
                        *m = 2; 
                    }
                    *p = 1;
                    break;
                    
                case 2:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        t[0] = t[1];
                        t[1] = t[2];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        t[1] = t[2];
                    }
                    *t3 = 0;
                    t[2] = 0;
                    if(*t_out == 0){
                        *m = 3; 
                    }
                    *p = 1;
                    break;
                    
                case 3:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        t[2] = t[3];
                    }
                    *t4 = 0;
                    t[3] = 0;
                    if(*t_out == 0){
                        *m = 4; 
                    }
                    *p = 1;
                    break;
                    
                case 4:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        *t4 = *t5;
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[3] == 0){
                        *t4 == *t5;
                        t[3] = t[4];
                    }
                    *t5 = 0;
                    t[4] = 0;
                    if(*t_out == 0){
                        *m = 5; 
                    }
                    *p = 1;
                    break;
                    
                    default:
                    break;
                }

                break;

            case 4:
                *m = *b;
                *p = 1;

                break;
            
            default:
                break;
            }
            
            break;

        case 12://Timer 2
            switch (*p)
            {
            case 2:
                if(t_pause[1]){
                    t_pause[1] = 0;
                }
                else{
                    t_pause[1] = 1;
                }

                break;

            case 3:
                *act_t--;
                
                switch (*act_t)
                {
                case 0:
                    *t1 = 0;
                    *m = 1;
                    *p = 1;
                    break;
                    
                case 1:
                    if(t[0] == 0){
                        *t1 = *t2;
                        t[0] = t[1];
                    }
                    *t2 = 0;
                    t[1] = 0;
                    if(*t_out == 0){
                        *m = 2; 
                    }
                    *p = 1;
                    break;
                    
                case 2:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        t[0] = t[1];
                        t[1] = t[2];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        t[1] = t[2];
                    }
                    *t3 = 0;
                    t[2] = 0;
                    if(*t_out == 0){
                        *m = 3; 
                    }
                    *p = 1;
                    break;
                    
                case 3:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        t[2] = t[3];
                    }
                    *t4 = 0;
                    t[3] = 0;
                    if(*t_out == 0){
                        *m = 4; 
                    }
                    *p = 1;
                    break;
                    
                case 4:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        *t4 = *t5;
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[3] == 0){
                        *t4 == *t5;
                        t[3] = t[4];
                    }
                    *t5 = 0;
                    t[4] = 0;
                    if(*t_out == 0){
                        *m = 5; 
                    }
                    *p = 1;
                    break;
                    
                    default:
                    break;
                }

                break;

            case 4:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
            
            break;
            
        case 13://Timer 3
            switch (*p)
            {
            case 2:
                if(t_pause[2]){
                    t_pause[2] = 0;
                }
                else{
                    t_pause[2] = 1;
                }

                break;

            case 3:
                *act_t--;
                switch (*act_t)
                {
                case 0:
                    *t1 = 0;
                    *m = 1;
                    *p = 1;
                    break;
                    
                case 1:
                    if(t[0] == 0){
                        *t1 = *t2;
                        t[0] = t[1];
                    }
                    *t2 = 0;
                    t[1] = 0;
                    if(*t_out == 0){
                        *m = 2; 
                    }
                    *p = 1;
                    break;
                    
                case 2:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        t[0] = t[1];
                        t[1] = t[2];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        t[1] = t[2];
                    }
                    *t3 = 0;
                    t[2] = 0;
                    if(*t_out == 0){
                        *m = 3; 
                    }
                    *p = 1;
                    break;
                    
                case 3:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        t[2] = t[3];
                    }
                    *t4 = 0;
                    t[3] = 0;
                    if(*t_out == 0){
                        *m = 4; 
                    }
                    *p = 1;
                    break;
                    
                case 4:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        *t4 = *t5;
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[3] == 0){
                        *t4 == *t5;
                        t[3] = t[4];
                    }
                    *t5 = 0;
                    t[4] = 0;
                    if(*t_out == 0){
                        *m = 5; 
                    }
                    *p = 1;
                    break;
                    
                    default:
                    break;
                }

                break;

            case 4:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
            
            break;
            
        case 14://Timer 4
            switch (*p)
            {
            case 2:
                if(t_pause[3]){
                    t_pause[3] = 0;
                }
                else{
                    t_pause[3] = 1;
                }

                break;

            case 3:
                *act_t--;
                switch (*act_t)
                {
                case 0:
                    *t1 = 0;
                    *m = 1;
                    *p = 1;
                    break;
                    
                case 1:
                    if(t[0] == 0){
                        *t1 = *t2;
                        t[0] = t[1];
                    }
                    *t2 = 0;
                    t[1] = 0;
                    if(*t_out == 0){
                        *m = 2; 
                    }
                    *p = 1;
                    break;
                    
                case 2:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        t[0] = t[1];
                        t[1] = t[2];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        t[1] = t[2];
                    }
                    *t3 = 0;
                    t[2] = 0;
                    if(*t_out == 0){
                        *m = 3; 
                    }
                    *p = 1;
                    break;
                    
                case 3:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        t[2] = t[3];
                    }
                    *t4 = 0;
                    t[3] = 0;
                    if(*t_out == 0){
                        *m = 4; 
                    }
                    *p = 1;
                    break;
                    
                case 4:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        *t4 = *t5;
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[3] == 0){
                        *t4 == *t5;
                        t[3] = t[4];
                    }
                    *t5 = 0;
                    t[4] = 0;
                    if(*t_out == 0){
                        *m = 5; 
                    }
                    *p = 1;
                    break;
                    
                    default:
                    break;
                }

                break;

            case 4:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
            
            break;
            
        case 15://Timer 5
            switch (*p)
            {
            case 2:
                if(t_pause[4]){
                    t_pause[4] = 0;
                }
                else{
                    t_pause[4] = 1;
                }

                break;

            case 3:
                *act_t--;
                switch (*act_t)
                {
                case 0:
                    *t1 = 0;
                    *m = 1;
                    *p = 1;
                    break;
                    
                case 1:
                    if(t[0] == 0){
                        *t1 = *t2;
                        t[0] = t[1];
                    }
                    *t2 = 0;
                    t[1] = 0;
                    if(*t_out == 0){
                        *m = 2; 
                    }
                    *p = 1;
                    break;
                    
                case 2:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        t[0] = t[1];
                        t[1] = t[2];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        t[1] = t[2];
                    }
                    *t3 = 0;
                    t[2] = 0;
                    if(*t_out == 0){
                        *m = 3; 
                    }
                    *p = 1;
                    break;
                    
                case 3:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        t[1] = t[2];
                        t[2] = t[3];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        t[2] = t[3];
                    }
                    *t4 = 0;
                    t[3] = 0;
                    if(*t_out == 0){
                        *m = 4; 
                    }
                    *p = 1;
                    break;
                    
                case 4:
                    if(t[0] == 0){
                        *t1 = *t2;
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[0] = t[1];
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[1] == 0){
                        *t2 = *t3;
                        *t3 = *t4;
                        *t4 = *t5;
                        t[1] = t[2];
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[2] == 0){
                        *t3 = *t4;
                        *t4 = *t5;
                        t[2] = t[3];
                        t[3] = t[4];
                    }
                    else if(t[3] == 0){
                        *t4 == *t5;
                        t[3] = t[4];
                    }
                    *t5 = 0;
                    t[4] = 0;
                    if(*t_out == 0){
                        *m = 5; 
                    }
                    *p = 1;
                    break;
                    
                    default:
                    break;
                }

                break;

            case 4:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
            
            break;
            
        default:
            break;
        }
}