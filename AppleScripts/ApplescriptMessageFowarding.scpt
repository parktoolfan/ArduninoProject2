FasdUAS 1.101.10   ��   ��    k             i         I      �� 	���� 
0 report   	  
�� 
 o      ���� 0 errorpayload ErrorPayload��  ��    k     -       O     
    I   	������
�� .Itrmnwwnnull��� ��� null��  ��    m       �                                                                                  ITRM  alis    0  SSDX                       ҥ��H+     r	iTerm.app                                                       ����lے        ����  	                Applications    Ҧ      �m!�       r  SSDX:Applications: iTerm.app   	 i T e r m . a p p  
  S S D X  Applications/iTerm.app  / ��        l   ��������  ��  ��     ��  O    -    k    ,       l        I   �� ��
�� .prcskprsnull���     ctxt  b        m       �     
 p u s h    o    ���� 0 errorpayload ErrorPayload��    ' !using {option down, command down}     � ! ! B u s i n g   { o p t i o n   d o w n ,   c o m m a n d   d o w n }   " # " I   �� $��
�� .prcskprsnull���     ctxt $ o    ��
�� 
ret ��   #  % & % I   "�� '��
�� .sysodelanull��� ��� nmbr ' m    ���� ��   &  (�� ( I  # ,�� ) *
�� .prcskprsnull���     ctxt ) m   # $ + + � , ,  w * �� -��
�� 
faal - J   % ( . .  /�� / m   % &��
�� eMdsKcmd��  ��  ��    m     0 0�                                                                                  sevs  alis    z  SSDX                       ҥ��H+   �:System Events.app                                               D����        ����  	                CoreServices    Ҧ      ����     �: �,   t  5SSDX:System: Library: CoreServices: System Events.app   $  S y s t e m   E v e n t s . a p p  
  S S D X  -System/Library/CoreServices/System Events.app   / ��  ��     1 2 1 l     ��������  ��  ��   2  3�� 3 l    � 4���� 4 Q     � 5 6 7 5 k    � 8 8  9 : 9 O    $ ; < ; k    # = =  > ? > l   ��������  ��  ��   ?  @ A @ r     B C B n     D E D 4    �� F
�� 
mssg F m    ����  E 4    �� G
�� 
mbxp G m   	 
 H H � I I  T e x t C o      ���� 0 
themessage 
theMessage A  J K J l   ��������  ��  ��   K  L M L r     N O N o    ���� 0 
themessage 
theMessage O o      ���� 0 theselection theSelection M  P Q P r     R S R n     T U T 4    �� V
�� 
cobj V m    ����  U o    ���� 0 theselection theSelection S o      ���� 0 
themessage 
theMessage Q  W X W r    ! Y Z Y n     [ \ [ 1    ��
�� 
ctnt \ o    ���� 0 
themessage 
theMessage Z o      ���� 0 	emailbody 	EmailBody X  ]�� ] l  " "��������  ��  ��  ��   < m     ^ ^�                                                                                  emal  alis    .  SSDX                       ҥ��H+     rMail.app                                                          ��>�        ����  	                Applications    Ҧ      �>Q�       r  SSDX:Applications: Mail.app     M a i l . a p p  
  S S D X  Applications/Mail.app   / ��   :  _ ` _ l  % %��������  ��  ��   `  a b a I  % *�� c��
�� .sysonotfnull��� ��� TEXT c o   % &���� 0 	emailbody 	EmailBody��   b  d e d l  + +��������  ��  ��   e  f g f l   + +�� h i��   h��--set AppleScript's text item delimiters to {"MESSAGE"}		--set TheBuddy to text item 1 of EmailBody		--set payloadmessage to text item 2 of EmailBody	
	
		try		tell application "Messages"			send payloadmessage to buddy TheBuddy of service "SMS"		end tell	on error errorMessage number errorNumber		display notification ("errorMessage: " & errorMessage & ", errorNumber: " & errorNumber)	end try	try		tell application "Messages"			send payloadmessage to buddy TheBuddy of service "E:theostangebye@icloud.com"		end tell	on error errorMessage number errorNumber		display notification ("errorMessage: " & errorMessage & ", errorNumber: " & errorNumber)	end try    i � j jH  - - s e t   A p p l e S c r i p t ' s   t e x t   i t e m   d e l i m i t e r s   t o   { " M E S S A G E " }  	  	 - - s e t   T h e B u d d y   t o   t e x t   i t e m   1   o f   E m a i l B o d y  	  	 - - s e t   p a y l o a d m e s s a g e   t o   t e x t   i t e m   2   o f   E m a i l B o d y  	 
 	 
 	  	 t r y  	 	 t e l l   a p p l i c a t i o n   " M e s s a g e s "  	 	 	 s e n d   p a y l o a d m e s s a g e   t o   b u d d y   T h e B u d d y   o f   s e r v i c e   " S M S "  	 	 e n d   t e l l  	 o n   e r r o r   e r r o r M e s s a g e   n u m b e r   e r r o r N u m b e r  	 	 d i s p l a y   n o t i f i c a t i o n   ( " e r r o r M e s s a g e :   "   &   e r r o r M e s s a g e   &   " ,   e r r o r N u m b e r :   "   &   e r r o r N u m b e r )  	 e n d   t r y  	 t r y  	 	 t e l l   a p p l i c a t i o n   " M e s s a g e s "  	 	 	 s e n d   p a y l o a d m e s s a g e   t o   b u d d y   T h e B u d d y   o f   s e r v i c e   " E : t h e o s t a n g e b y e @ i c l o u d . c o m "  	 	 e n d   t e l l  	 o n   e r r o r   e r r o r M e s s a g e   n u m b e r   e r r o r N u m b e r  	 	 d i s p l a y   n o t i f i c a t i o n   ( " e r r o r M e s s a g e :   "   &   e r r o r M e s s a g e   &   " ,   e r r o r N u m b e r :   "   &   e r r o r N u m b e r )  	 e n d   t r y  g  k l k l  + +��������  ��  ��   l  m n m r   + 2 o p o J   + . q q  r�� r m   + , s s � t t  M E S S A G E��   p n      u v u 1   / 1��
�� 
txdl v 1   . /��
�� 
ascr n  w x w l  3 3��������  ��  ��   x  y z y l  3 3�� { |��   { . (set TheBuddy to text item 1 of EmailBody    | � } } P s e t   T h e B u d d y   t o   t e x t   i t e m   1   o f   E m a i l B o d y z  ~  ~ l  3 3��������  ��  ��     � � � r   3 9 � � � n   3 7 � � � 4   4 7�� �
�� 
citm � m   5 6����  � o   3 4���� 0 	emailbody 	EmailBody � o      ���� 0 payloadmessage   �  � � � l  : :��������  ��  ��   �  � � � r   : ? � � � m   : ; � � � � �  5 7 0 6 6 0 1 4 8 3 � o      ���� 0 thebuddy TheBuddy �  � � � l  @ @��������  ��  ��   �  � � � Q   @ x � � � � O   C a � � � I  I `�� � �
�� .ichtsendnull���     **** � o   I J���� 0 payloadmessage   � �� ���
�� 
TO   � n   M \ � � � 4   U \�� �
�� 
pres � o   X [���� 0 thebuddy TheBuddy � 4   M U�� �
�� 
icsv � m   Q T � � � � �  S M S��   � m   C F � ��                                                                                  fez!  alis    >  SSDX                       ҥ��H+     rMessages.app                                                      ��ʹ�        ����  	                Applications    Ҧ      ���?       r  SSDX:Applications: Messages.app     M e s s a g e s . a p p  
  S S D X  Applications/Messages.app   / ��   � R      �� � �
�� .ascrerr ****      � **** � o      ���� 0 errormessage errorMessage � �� ���
�� 
errn � o      ���� 0 errornumber errorNumber��   � I  i x�� ���
�� .sysonotfnull��� ��� TEXT � l  i t ����� � b   i t � � � b   i r � � � b   i n � � � m   i l � � � � �  e r r o r M e s s a g e :   � o   l m���� 0 errormessage errorMessage � m   n q � � � � �  ,   e r r o r N u m b e r :   � o   r s���� 0 errornumber errorNumber��  ��  ��   �  � � � Q   y � � � � � O   | � � � � I  � ��� � �
�� .ichtsendnull���     **** � o   � ����� 0 payloadmessage   � �� ���
�� 
TO   � n   � � � � � 4   � ��� �
�� 
pres � o   � ����� 0 thebuddy TheBuddy � 4   � ��� �
�� 
icsv � m   � � � � � � � 4 E : t h e o s t a n g e b y e @ i c l o u d . c o m��   � m   |  � ��                                                                                  fez!  alis    >  SSDX                       ҥ��H+     rMessages.app                                                      ��ʹ�        ����  	                Applications    Ҧ      ���?       r  SSDX:Applications: Messages.app     M e s s a g e s . a p p  
  S S D X  Applications/Messages.app   / ��   � R      �� � �
�� .ascrerr ****      � **** � o      ���� 0 errormessage errorMessage � �� ���
�� 
errn � o      ���� 0 errornumber errorNumber��   � I  � ��� ���
�� .sysonotfnull��� ��� TEXT � l  � � ����� � b   � � � � � b   � � � � � b   � � � � � m   � � � � � � �  e r r o r M e s s a g e :   � o   � ����� 0 errormessage errorMessage � m   � � � � � � �  ,   e r r o r N u m b e r :   � o   � ����� 0 errornumber errorNumber��  ��  ��   �  � � � l  � ��������  ��  �   �  � � � I  � ��~ ��}
�~ .sysodelanull��� ��� nmbr � m   � ��|�| 
�}   �  � � � l  � ��{�z�y�{  �z  �y   �  � � � O   � � � � � I  � ��x � �
�x .coremovenull���     obj  � o   � ��w�w 0 
themessage 
theMessage � �v ��u
�v 
insh � n   � � � � � 4   � ��t �
�t 
mbxp � m   � � � � � � � 
 T r a s h � 4   � ��s �
�s 
mact � m   � � � � � � �  G o o g l e�u   � m   � � � ��                                                                                  emal  alis    .  SSDX                       ҥ��H+     rMail.app                                                          ��>�        ����  	                Applications    Ҧ      �>Q�       r  SSDX:Applications: Mail.app     M a i l . a p p  
  S S D X  Applications/Mail.app   / ��   �  ��r � l  � ��q�p�o�q  �p  �o  �r   6 R      �n � �
�n .ascrerr ****      � **** � o      �m�m 0 errormessage errorMessage � �l ��k
�l 
errn � o      �j�j 0 errornumber errorNumber�k   7 I   � ��i ��h�i 
0 report   �  ��g � b   � � � � � b   � � � � � b   � � � � � m   � � � � � � � ` E r r o r   o n   E m a i l T o T e x t A p p l e s c r i p t :     e r r o r M e s s a g e :   � o   � ��f�f 0 errormessage errorMessage � m   � � � � � � �  ,   e r r o r N u m b e r :   � o   � ��e�e 0 errornumber errorNumber�g  �h  ��  ��  ��       �d � � ��d   � �c�b�c 
0 report  
�b .aevtoappnull  �   � **** � �a �`�_ � ��^�a 
0 report  �` �] ��]  �  �\�\ 0 errorpayload ErrorPayload�_   � �[�[ 0 errorpayload ErrorPayload � 
 �Z 0 �Y�X�W +�V�U
�Z .Itrmnwwnnull��� ��� null
�Y .prcskprsnull���     ctxt
�X 
ret 
�W .sysodelanull��� ��� nmbr
�V 
faal
�U eMdsKcmd�^ .� *j UO� �%j O�j Okj O���kvl U � �T ��S�R � �Q
�T .aevtoappnull  �   � **** � k     �  3�P�P  �S  �R   � �O�N�O 0 errormessage errorMessage�N 0 errornumber errorNumber  ( ^�M H�L�K�J�I�H�G�F s�E�D�C�B ��A ��@�? ��>�=�< � � � � ��;�:�9�8 � ��7 � ��6
�M 
mbxp
�L 
mssg�K 0 
themessage 
theMessage�J 0 theselection theSelection
�I 
cobj
�H 
ctnt�G 0 	emailbody 	EmailBody
�F .sysonotfnull��� ��� TEXT
�E 
ascr
�D 
txdl
�C 
citm�B 0 payloadmessage  �A 0 thebuddy TheBuddy
�@ 
TO  
�? 
icsv
�> 
pres
�= .ichtsendnull���     ****�< 0 errormessage errorMessage �5�4�3
�5 
errn�4 0 errornumber errorNumber�3  �; 

�: .sysodelanull��� ��� nmbr
�9 
insh
�8 
mact
�7 .coremovenull���     obj �6 
0 report  �Q � �� *��/�k/E�O�E�O��k/E�O��,E�OPUO�j 	O�kv��,FO��k/E�O�E` O #a  �a *a a /a _ /l UW X  a �%a %�%j 	O #a  �a *a a /a _ /l UW X  a �%a %�%j 	Oa j O� �a  *a !a "/�a #/l $UOPW X  *a %�%a &%�%k+ 'ascr  ��ޭ