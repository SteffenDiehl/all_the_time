void Rotary_Click(int *m, int *p, int *b, int *Wi_Fi, int *Web_Server){
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

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;

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

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;

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

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;

                break;

            case 4:
                *b = *m;
                *m = 14;
                *p = 1;

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

                break;

            case 2:
                *b = *m;
                *m = 12;
                *p = 1;

                break;
            
            case 3:
                *b = *m;
                *m = 13;
                *p = 1;

                break;

            case 4:
                *b = *m;
                *m = 14;
                *p = 1;

                break;

            case 5:
                *b = *m;
                *m = 15;
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
                if(*Web_Server == 0){
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
                *m = *b;
                *p = 1;

                break;
            
            default:
                break;
            }
        
        case 12://Timer 2
            switch (*p)
            {
            case 2:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
        
        case 13://Timer 3
            switch (*p)
            {
            case 2:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
        
        case 14://Timer 4
            switch (*p)
            {
            case 2:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }
        
        case 15://Timer 5
            switch (*p)
            {
            case 2:
                *m = *b;
                *p = 1;
                
                break;
            
            default:
                break;
            }

        default:

            break;
        }
}