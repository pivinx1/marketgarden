/* haha imagine having libraries, can't be me */
#include "fb.h"
#include "io.h"
#include "serial.h"

#define COM1 0x3F8

void kmain()
{
    initialize_serial(COM1);
    terminal_initialize();
    kprint("MarketGardenOS 0.0.1 powered by DuctTape Kernel\n");
    kprint("Initializing...\n");
    kprint("[INFO] Debug output active on COM1, 9600-8-N-1\n");
    kprint_serial("[INFO] Serial log active\n", COM1);
    
    terminal_setcolor(4 | 15 << 4);
    kprint("                   @%%#######%%%@@@@\n");                       
    kprint("         @@%%########%@@@@@@@@@@\n");                      
    kprint("      @@%#########%%%@@%@@@@@@@@\n");                       
    kprint("       @%###########%%%##@%@@@@@@@@\n");                        
    kprint("     %###########%###%%##@%@%@@@@@@\n");                        
    kprint("   %##################%##%@%%@@@@@@\n");                        
    kprint(" @%###################%###@%%@@@@@\n");                         
    kprint(" %#########%%##########%##%@%%@@@@\n");                         
    kprint("@########%@@@@%############@%%@@@@@\n");                        
    kprint("    @@@%%@@@@@@@@@@#########%##%%%@@@@@               +%\n");       
    kprint("   @@@@@@@@@@@@##########%##@%%@@@@@   @@ @@@@%+-==\n");        
    kprint("     @@@@@@@@@@%##########%#%@%@@@@@@@@@@@@@#-.=%@@\n");        
    kprint("       @@@@@@@@@@%########%##@@@@@%%@@@@%@@+.-+@@@@%=+#@@@\n"); 
    kprint("        @@@@@@@@@@%########%@%@@%%@@@@@+#@@%%@@@@@-+@@\n");     
    kprint("         @@@@@@@@@@%######%##%%%@@@@%=*@@%####%@@=%@@@@\n");    
    kprint("           @@@@@@@@@@###%###%%@@@@=.:*%###+%##@#:#@@@@@\n");    
    kprint("            @@@@@@@@@@%####%%@@@%.  :*##=-%###-.+@@@@@@\n");    
    kprint("            @@@@@@%#######%%@@@@=.. .+#+:.--...-%@@@@@@\n");    
    kprint("             @@@@@%########@@%##=.   .:-=++::-*@@@@@@@\n");     
    kprint("           @@@@@@@@#######@**###:.. .-#####%@@@@@@@@@\n");      
    kprint("       @@@@@@@@@@@@@#####@*.+%#=.  .:#####%@@@@@@@@@\n");       
    kprint("     @@@%######@@@@@%#%%%@- ....   ..=#%#%@@@@@@@@\n");         
    kprint("   @@%##########@@@@@@%%%-. ..     ..=##%@@@@@@\n");            
    kprint("   @%#############%@%%%%#+..    .-+*###%@@@@@\n");              
    kprint("   @%###############%%###-..   -*##%%#%@@\n");                  
    kprint("    @%##########%%#@@###:     ....-##%@\n");                    
    kprint("       @%######%@@@@%##*:*###=-+%%##@@\n");                     
    kprint("          @@@@@@:.:#@%############%@\n");                       
    kprint("              @@@@**@%%%########%@\n");                         
    kprint("                 @@@@@@    @@@@@\n");                           
    kprint("                   @@\n");                                     
    kprint("             T A K E    Y O U R    H E A R T\n");
    
    terminal_setcolor(7 | 0 << 4); 
    kprint("this shit\nis so ass");
    
    kprint_serial("[INFO] kmain execution complete\n", COM1);
}
