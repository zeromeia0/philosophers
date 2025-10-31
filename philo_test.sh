#!/bin/bash

##########################
# TESTING WITH ONLY ZEROS AND ONES
##########################
echo "testing ./philo 0 0 0 0"
if timeout 0.1s ./philo 0 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 0 1"
if timeout 0.1s ./philo 0 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 0"
if timeout 0.1s ./philo 0 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 1"
if timeout 0.1s ./philo 0 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 0"
if timeout 0.1s ./philo 0 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 1"
if timeout 0.1s ./philo 0 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 0"
if timeout 0.1s ./philo 0 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 1"
if timeout 0.1s ./philo 0 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 0"
if timeout 0.1s ./philo 1 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 1"
if timeout 0.1s ./philo 1 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 0"
if timeout 0.1s ./philo 1 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 1"
if timeout 0.1s ./philo 1 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 0"
if timeout 0.1s ./philo 1 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 1"
if timeout 0.1s ./philo 1 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


echo "testing ./philo 1 1 1 0"
if timeout 0.1s ./philo 1 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 1 1 1 1"
if timeout 0.1s ./philo 1 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# # TESTING WITH WORKING NUMBER OF PHILO
# ##########################
echo "testing ./philo 2 0 0 0"
if timeout 0.1s ./philo 2 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 0 1"
if timeout 0.1s ./philo 2 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 1 0"
if timeout 0.1s ./philo 2 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 1 1"
if timeout 0.1s ./philo 2 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 0 0"
if timeout 0.1s ./philo 2 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 0 1"
if timeout 0.1s ./philo 2 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 1 0"
if timeout 0.1s ./philo 2 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 1 1"
if timeout 0.1s ./philo 2 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# # TESTING WITH '-' VALUES
# ##########################
echo "testing ./philo -2 410 200 200"
if timeout 0.1s ./philo -2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -410 200 200"
if timeout 0.1s ./philo 2 -410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -200 200"
if timeout 0.1s ./philo 2 410 -200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -200"
if timeout 0.1s ./philo 2 410 200 -200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

# ##########################
# # TESTING WITH '+-' VALUES
# ##########################
echo "testing ./philo +-2 410 200 200"
if timeout 0.1s ./philo +-2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +-410 200 200"
if timeout 0.1s ./philo 2 +-410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 +-200 200"
if timeout 0.1s ./philo 2 410 +-200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 +-200"
if timeout 0.1s ./philo 2 410 200 +-200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 410 200 200"
if timeout 0.1s ./philo -+2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -+410 200 200"
if timeout 0.1s ./philo 2 -+410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -+200 200"
if timeout 0.1s ./philo 2 410 -+200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -+200"
if timeout 0.1s ./philo 2 410 200 -+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# ##########################
# # TESTING WITH '+-' + ZEROS VALUES
# ##########################
echo "testing ./philo -000+002 +00410 0+200 0-200"
if timeout 0.1s ./philo -000+002 +00410 0+200 0-200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 0-0410 200 200"
if timeout 0.1s ./philo 00+2 0-0410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +0-2 -0+410 +0-200 -0+200"
if timeout 0.1s ./philo +0-2 -0+410 +0-200 -0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0+02 0410 -0200 +0200"
if timeout 0.1s ./philo 0+02 0410 -0200 +0200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +410 00-200 0+200"
if timeout 0.1s ./philo 2 +410 00-200 0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 +-410 +00200 -00200"
if timeout 0.1s ./philo -+2 +-410 +00200 -00200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +02 0+0410 +0-200 -0+200"
if timeout 0.1s ./philo +02 0+0410 +0-200 -0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 -00410 +0200 -0200"
if timeout 0.1s ./philo 00+2 -00410 +0200 -0200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


echo "testing ./philo a2 410 200 200"
if timeout 0.1s ./philo a2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2a 410 200 200"
if timeout 0.1s ./philo 2a 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 a410 200 200"
if timeout 0.1s ./philo 2 a410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410a 200 200"
if timeout 0.1s ./philo 2 410a 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 a200 200"
if timeout 0.1s ./philo 2 410 a200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200a 200"
if timeout 0.1s ./philo 2 410 200a 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 a200"
if timeout 0.1s ./philo 2 410 200 a200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200a"
if timeout 0.1s ./philo 2 410 200 200a 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# ##########################
# # TESTING WITH ZEROS
# ##########################
# echo "testing ./philo 000002 410 200 200"; ./philo 000002 410 200 200
# echo "testing ./philo 2 00000410 200 200"; ./philo 2 00000410 200 200
# echo "testing ./philo 2 410 000000200 200"; ./philo 2 410 000000200 200
# echo "testing ./philo 2 410 200 00000000000200"; ./philo 2 410 200 00000000000200
# echo "testing ./philo 02 00410 200 200"; ./philo 02 00410 200 200
# echo "testing ./philo 02 00410 00200 000200"; ./philo 02 00410 00200 000200
# echo "testing ./philo 000002 0410 200 00000200"; ./philo 000002 0410 200 00000200
# echo "testing ./philo 2 0000410 200 00000200"; ./philo 2 0000410 200 00000200

# ##########################
# # TESTING WITH '+' VALUES
# ##########################
# echo "testing ./philo +2 410 200 200"; ./philo +2 410 200 200
# echo "testing ./philo 2 +410 200 200"; ./philo 2 +410 200 200
# echo "testing ./philo 2 410 +200 200"; ./philo 2 410 +200 200
# echo "testing ./philo 2 410 200 +200"; ./philo 2 410 200 +200

# ##########################
# # TESTING QUANTITY OF ARGUMENTS
# ##########################
# echo "testing ./philo"; ./philo
# echo "testing ./philo 2"; ./philo 2
# echo "testing ./philo 2 410"; ./philo 2 410
# echo "testing ./philo 2 410 200"; ./philo 2 410 200
# echo "testing ./philo 2 410 200 200 200"; ./philo 2 410 200 200 200
# echo "testing ./philo 2 410 200 200 200 200"; ./philo 2 410 200 200 200 200

# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT ONLY ZERO
# ##########################
# echo "testing ./philo 0 0 0 0 0"; ./philo 0 0 0 0 0
# echo "testing ./philo 0 0 0 0 1"; ./philo 0 0 0 0 1
# echo "testing ./philo 0 0 0 1 0"; ./philo 0 0 0 1 0
# echo "testing ./philo 0 0 0 1 1"; ./philo 0 0 0 1 1
# echo "testing ./philo 0 0 1 0 0"; ./philo 0 0 1 0 0
# echo "testing ./philo 0 0 1 0 1"; ./philo 0 0 1 0 1
# echo "testing ./philo 0 0 1 1 0"; ./philo 0 0 1 1 0
# echo "testing ./philo 0 0 1 1 1"; ./philo 0 0 1 1 1
# echo "testing ./philo 0 1 0 0 0"; ./philo 0 1 0 0 0
# echo "testing ./philo 0 1 0 0 1"; ./philo 0 1 0 0 1
# echo "testing ./philo 0 1 0 1 0"; ./philo 0 1 0 1 0
# echo "testing ./philo 0 1 0 1 1"; ./philo 0 1 0 1 1
# echo "testing ./philo 0 1 1 0 0"; ./philo 0 1 1 0 0
# echo "testing ./philo 0 1 1 0 1"; ./philo 0 1 1 0 1
# echo "testing ./philo 0 1 1 1 0"; ./philo 0 1 1 1 0
# echo "testing ./philo 0 1 1 1 1"; ./philo 0 1 1 1 1
# echo "testing ./philo 1 0 0 0 0"; ./philo 1 0 0 0 0
# echo "testing ./philo 1 0 0 0 1"; ./philo 1 0 0 0 1
# echo "testing ./philo 1 0 0 1 0"; ./philo 1 0 0 1 0
# echo "testing ./philo 1 0 0 1 1"; ./philo 1 0 0 1 1
# echo "testing ./philo 1 0 1 0 0"; ./philo 1 0 1 0 0
# echo "testing ./philo 1 0 1 0 1"; ./philo 1 0 1 0 1
# echo "testing ./philo 1 0 1 1 0"; ./philo 1 0 1 1 0
# echo "testing ./philo 1 0 1 1 1"; ./philo 1 0 1 1 1
# echo "testing ./philo 1 1 0 0 0"; ./philo 1 1 0 0 0
# echo "testing ./philo 1 1 0 0 1"; ./philo 1 1 0 0 1
# echo "testing ./philo 1 1 0 1 0"; ./philo 1 1 0 1 0
# echo "testing ./philo 1 1 0 1 1"; ./philo 1 1 0 1 1
# echo "testing ./philo 1 1 1 0 0"; ./philo 1 1 1 0 0
# echo "testing ./philo 1 1 1 0 1"; ./philo 1 1 1 0 1
# echo "testing ./philo 1 1 1 1 0"; ./philo 1 1 1 1 0
# echo "testing ./philo 1 1 1 1 1"; ./philo 1 1 1 1 1

# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT VALID PHILO NUMBER
# ##########################

# echo "testing ./philo 2 0 0 0 0"; ./philo 2 0 0 0 0
# echo "testing ./philo 2 0 0 0 1"; ./philo 2 0 0 0 1
# echo "testing ./philo 2 0 0 1 0"; ./philo 2 0 0 1 0
# echo "testing ./philo 2 0 0 1 1"; ./philo 2 0 0 1 1
# echo "testing ./philo 2 0 1 0 0"; ./philo 2 0 1 0 0
# echo "testing ./philo 2 0 1 0 1"; ./philo 2 0 1 0 1
# echo "testing ./philo 2 0 1 1 0"; ./philo 2 0 1 1 0
# echo "testing ./philo 2 0 1 1 1"; ./philo 2 0 1 1 1
# echo "testing ./philo 2 1 0 0 0"; ./philo 2 1 0 0 0
# echo "testing ./philo 2 1 0 0 1"; ./philo 2 1 0 0 1
# echo "testing ./philo 2 1 0 1 0"; ./philo 2 1 0 1 0
# echo "testing ./philo 2 1 0 1 1"; ./philo 2 1 0 1 1
# echo "testing ./philo 2 1 1 0 0"; ./philo 2 1 1 0 0
# echo "testing ./philo 2 1 1 0 1"; ./philo 2 1 1 0 1
# echo "testing ./philo 2 1 1 1 0"; ./philo 2 1 1 1 0
# echo "testing ./philo 2 1 1 1 1"; ./philo 2 1 1 1 1

# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT + LETTERS
# ##########################
# echo "testing ./philo a2 410 200 200 1"; ./philo a2 410 200 200 1
# echo "testing ./philo 2a 410 200 200 1"; ./philo 2a 410 200 200 1
# echo "testing ./philo 2 a410 200 200 1"; ./philo 2 a410 200 200 1
# echo "testing ./philo 2 410a 200 200 1"; ./philo 2 410a 200 200 1
# echo "testing ./philo 2 410 a200 200 1"; ./philo 2 410 a200 200 1
# echo "testing ./philo 2 410 200a 200 1"; ./philo 2 410 200a 200 1
# echo "testing ./philo 2 410 200 a200 1"; ./philo 2 410 200 a200 1
# echo "testing ./philo 2 410 200 200a 1"; ./philo 2 410 200 200a 1
# echo "testing ./philo 2 410 200 200 a1"; ./philo 2 410 200 200 a1
# echo "testing ./philo 2 410 200 200 1a"; ./philo 2 410 200 200 1a


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + ZEROS
# ##########################################
# echo "testing ./philo 000002 410 200 200 1"; ./philo 000002 410 200 200 1
# echo "testing ./philo 2 00000410 200 200 1"; ./philo 2 00000410 200 200 1
# echo "testing ./philo 2 410 000000200 200 1"; ./philo 2 410 000000200 200 1
# echo "testing ./philo 2 410 200 00000000000200 1"; ./philo 2 410 200 00000000000200 1
# echo "testing ./philo 02 00410 200 200 1"; ./philo 02 00410 200 200 1
# echo "testing ./philo 02 00410 00200 000200 1"; ./philo 02 00410 00200 000200 1
# echo "testing ./philo 000002 0410 200 00000200 1"; ./philo 000002 0410 200 00000200 1
# echo "testing ./philo 2 0000410 200 00000200 1"; ./philo 2 0000410 200 00000200 1
# echo "testing ./philo 2 410 200 200 00000000000200"; ./philo 2 410 200 200 00000000000200

# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + PLUS
# ##########################################
# echo "testing ./philo +2 410 200 200 1"; ./philo +2 410 200 200 1
# echo "testing ./philo 2 +410 200 200 1"; ./philo 2 +410 200 200 1
# echo "testing ./philo 2 410 +200 200 1"; ./philo 2 410 +200 200 1
# echo "testing ./philo 2 410 200 +200 1"; ./philo 2 410 200 +200 1
# echo "testing ./philo 2 410 200 200 +1"; ./philo 2 410 200 200 +1

# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + MINUS
# ##########################################
# echo "testing ./philo -2 410 200 200 1"; ./philo -2 410 200 200 1
# echo "testing ./philo 2 -410 200 200 1"; ./philo 2 -410 200 200 1
# echo "testing ./philo 2 410 -200 200 1"; ./philo 2 410 -200 200 1
# echo "testing ./philo 2 410 200 -200 1"; ./philo 2 410 200 -200 1
# echo "testing ./philo 2 410 200 200 -1"; ./philo 2 410 200 200 -1

# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + MINUS AND PLUS
# ##########################################
# echo "testing ./philo +-2 410 200 200 1"; ./philo +-2 410 200 200 1
# echo "testing ./philo 2 +-410 200 200 1"; ./philo 2 +-410 200 200 1
# echo "testing ./philo 2 410 +-200 200 1"; ./philo 2 410 +-200 200 1
# echo "testing ./philo 2 410 200 +-200 1"; ./philo 2 410 200 +-200 1
# echo "testing ./philo -+2 410 200 200 1"; ./philo -+2 410 200 200 1
# echo "testing ./philo 2 -+410 200 200 1"; ./philo 2 -+410 200 200 1
# echo "testing ./philo 2 410 -+200 200 1"; ./philo 2 410 -+200 200 1
# echo "testing ./philo 2 410 200 -+200 1"; ./philo 2 410 200 -+200 1
# echo "testing ./philo 2 410 200 200 +-1"; ./philo 2 410 200 200 +-1

# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + CRAZY
# ##########################################
# echo "testing ./philo -000+002 +00410 0+200 0-200 1"; ./philo -000+002 +00410 0+200 0-200 1
# echo "testing ./philo 00+2 0-0410 200 200 1"; ./philo 00+2 0-0410 200 200 1
# echo "testing ./philo +0-2 -0+410 +0-200 -0+200 1"; ./philo +0-2 -0+410 +0-200 -0+200 1
# echo "testing ./philo 0+02 0410 -0200 +0200 1"; ./philo 0+02 0410 -0200 +0200 1
# echo "testing ./philo 2 +410 00-200 0+200 1"; ./philo 2 +410 00-200 0+200 1
# echo "testing ./philo -+2 +-410 +00200 -00200 1"; ./philo -+2 +-410 +00200 -00200 1
# echo "testing ./philo +02 0+0410 +0-200 -0+200 1"; ./philo +02 0+0410 +0-200 -0+200 1
# echo "testing ./philo 00+2 -00410 +0200 -0200 1"; ./philo 00+2 -00410 +0200 -0200 1
# echo "testing ./philo -000+002 +00410 0+200 0-200 0"; ./philo -000+002 +00410 0+200 0-200 0
# echo "testing ./philo 00+2 0-0410 200 200 0"; ./philo 00+2 0-0410 200 200 0
# echo "testing ./philo +0-2 -0+410 +0-200 -0+200 0"; ./philo +0-2 -0+410 +0-200 -0+200 0
# echo "testing ./philo 0+02 0410 -0200 +0200 0"; ./philo 0+02 0410 -0200 +0200 0
# echo "testing ./philo 2 +410 00-200 0+200 0"; ./philo 2 +410 00-200 0+200 0
# echo "testing ./philo -+2 +-410 +00200 -00200 0"; ./philo -+2 +-410 +00200 -00200 0
# echo "testing ./philo +02 0+0410 +0-200 -0+200 0"; ./philo +02 0+0410 +0-200 -0+200 0
# echo "testing ./philo 00+2 -00410 +0200 -0200 0"; ./philo 00+2 -00410 +0200 -0200 0

# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + WEIRD
# ##########################################
# echo "testing ./philo 2 410 200 200 a"; ./philo 2 410 200 200 a
# echo "testing ./philo 2 410 200 200 +"; ./philo 2 410 200 200 +
# echo "testing ./philo 2 410 200 200 -"; ./philo 2 410 200 200 -
# echo "testing ./philo 2 410 200 200 +-"; ./philo 2 410 200 200 +-
# echo "testing ./philo 2 410 200 200 000001"; ./philo 2 410 200 200 000001
# echo "testing ./philo 2 410 200 200 -000001"; ./philo 2 410 200 200 -000001
# echo "testing ./philo 2 410 200 200 +000001"; ./philo 2 410 200 200 +000001
