FasdUAS 1.101.10   ��   ��    k             l     ��  ��    ^ X Connect To Favorite and Synchronize With Rules (Requires Transmit version 4.0 or newer)     � 	 	 �   C o n n e c t   T o   F a v o r i t e   a n d   S y n c h r o n i z e   W i t h   R u l e s   ( R e q u i r e s   T r a n s m i t   v e r s i o n   4 . 0   o r   n e w e r )   
  
 l     ��  ��      2010 Panic Inc.     �       2 0 1 0   P a n i c   I n c .      l     ��  ��           �           l     ��  ��    ] W Demonstrates how to connect to a favorite and run a simple synchronization, as well as     �   �   D e m o n s t r a t e s   h o w   t o   c o n n e c t   t o   a   f a v o r i t e   a n d   r u n   a   s i m p l e   s y n c h r o n i z a t i o n ,   a s   w e l l   a s      l     ��  ��      how to specify rules.     �   ,   h o w   t o   s p e c i f y   r u l e s .      l     ��������  ��  ��      ��   l     !���� ! O      " # " k    ~ $ $  % & % l   �� ' (��   ' _ Y In Transmit 4, favorites are now objects and must be specified in a different way. Below    ( � ) ) �   I n   T r a n s m i t   4 ,   f a v o r i t e s   a r e   n o w   o b j e c t s   a n d   m u s t   b e   s p e c i f i e d   i n   a   d i f f e r e n t   w a y .   B e l o w &  * + * l   �� , -��   , a [ we're choosing the first occurrence of a favorite named "My Great Server"(it's possible to    - � . . �   w e ' r e   c h o o s i n g   t h e   f i r s t   o c c u r r e n c e   o f   a   f a v o r i t e   n a m e d   " M y   G r e a t   S e r v e r " ( i t ' s   p o s s i b l e   t o +  / 0 / l   �� 1 2��   1 3 - have multiple favorites with the same name).    2 � 3 3 Z   h a v e   m u l t i p l e   f a v o r i t e s   w i t h   t h e   s a m e   n a m e ) . 0  4 5 4 l   ��������  ��  ��   5  6 7 6 l   �� 8 9��   8 f ` Also, the favorites list can only be directly referenced within Transmit's tell block, which is    9 � : : �   A l s o ,   t h e   f a v o r i t e s   l i s t   c a n   o n l y   b e   d i r e c t l y   r e f e r e n c e d   w i t h i n   T r a n s m i t ' s   t e l l   b l o c k ,   w h i c h   i s 7  ; < ; l   �� = >��   = b \ why we're setting a variable below instead of looking up the favorite within the tab's tell    > � ? ? �   w h y   w e ' r e   s e t t i n g   a   v a r i a b l e   b e l o w   i n s t e a d   o f   l o o k i n g   u p   t h e   f a v o r i t e   w i t h i n   t h e   t a b ' s   t e l l <  @ A @ l   �� B C��   B   block.    C � D D    b l o c k . A  E F E l   ��������  ��  ��   F  G H G r     I J I n     K L K 4    �� M
�� 
cobj M m    ����  L l    N���� N 6    O P O 2   ��
�� 
FAvr P =    Q R Q 1   	 ��
�� 
pnam R m     S S � T T  S 3 A m a z o n A r d u i n o��  ��   J o      ���� 0 myfave myFave H  U V U l   $ W X Y W r    $ Z [ Z l   " \���� \ 6   " ] ^ ] 2   ��
�� 
SkRu ^ =   ! _ ` _ 1    ��
�� 
pnam ` m      a a � b b  N e w   R u l e��  ��   [ o      ���� 0 myrules myRules X , & must be a set, not an individual item    Y � c c L   m u s t   b e   a   s e t ,   n o t   a n   i n d i v i d u a l   i t e m V  d e d l  % %��������  ��  ��   e  f g f l  % %�� h i��   h B < Create a new window (and thus a single tab) for this script    i � j j x   C r e a t e   a   n e w   w i n d o w   ( a n d   t h u s   a   s i n g l e   t a b )   f o r   t h i s   s c r i p t g  k�� k O   % ~ l m l k   4 } n n  o p o I  4 =���� q
�� .TrAnConfnull���     TaBc��   q �� r��
�� 
CoFa r o   8 9���� 0 myfave myFave��   p  s t s l  > >��������  ��  ��   t  u v u l  > >�� w x��   w A ; Go into the local and remote folders that we want to sync.    x � y y v   G o   i n t o   t h e   l o c a l   a n d   r e m o t e   f o l d e r s   t h a t   w e   w a n t   t o   s y n c . v  z { z I  > M�� | }
�� .TrAnDiscnull���     FilV | 1   > C��
�� 
TaLV } �� ~��
�� 
DiPa ~ m   F I   � � � L ~ / D o c u m e n t s / T r a n s m i t A m a z o n S 3 S y n c F o l d e r��   {  � � � I  N ]�� � �
�� .TrAnDiscnull���     FilV � 1   N S��
�� 
TaRV � �� ���
�� 
DiPa � m   V Y � � � � �  a r d u i n o p r o j e c t��   �  � � � l  ^ ^��������  ��  ��   �  � � � l  ^ ^�� � ���   � ] W Run a basic sync from the current local folder to the current remote folder. (The sync    � � � � �   R u n   a   b a s i c   s y n c   f r o m   t h e   c u r r e n t   l o c a l   f o l d e r   t o   t h e   c u r r e n t   r e m o t e   f o l d e r .   ( T h e   s y n c �  � � � l  ^ ^�� � ���   � L F command has many options, so be sure to check Transmit's dictionary.)    � � � � �   c o m m a n d   h a s   m a n y   o p t i o n s ,   s o   b e   s u r e   t o   c h e c k   T r a n s m i t ' s   d i c t i o n a r y . ) �  � � � I  ^ s�� � �
�� .TrAnSyncnull���     FilV � 1   ^ c��
�� 
TaLV � �� � �
�� 
SyTo � 1   f k��
�� 
TaRV � �� ���
�� 
SySr � o   n o���� 0 myrules myRules��   �  � � � l  t t��������  ��  ��   �  � � � l  t t�� � ���   �   Close the connection.    � � � � ,   C l o s e   t h e   c o n n e c t i o n . �  ��� � I  t }�� ���
�� .coreclosnull���     obj  � 1   t y��
�� 
TaRV��  ��   m n   % 1 � � � 1   / 1��
�� 
doTa � l  % / ����� � I  % /���� �
�� .corecrel****      � null��   � �� � �
�� 
kocl � m   ' (��
�� 
docu � �� ���
�� 
insh �  ;   ) +��  ��  ��  ��   # m      � ��                                                                                  TrAn  alis    >  SSDX                       ҥ��H+     rTransmit.app                                                    ����r`6        ����  	                Applications    Ҧ      �r��       r  SSDX:Applications: Transmit.app     T r a n s m i t . a p p  
  S S D X  Applications/Transmit.app   / ��  ��  ��  ��       �� � ���   � ��
�� .aevtoappnull  �   � **** � �� ����� � ���
�� .aevtoappnull  �   � **** � k      � �   ����  ��  ��   �   �  ��� ��� S������ a���������������������� ���� ���������
�� 
FAvr �  
�� 
pnam
�� 
cobj�� 0 myfave myFave
�� 
SkRu�� 0 myrules myRules
�� 
kocl
�� 
docu
�� 
insh�� 
�� .corecrel****      � null
�� 
doTa
�� 
CoFa
�� .TrAnConfnull���     TaBc
�� 
TaLV
�� 
DiPa
�� .TrAnDiscnull���     FilV
�� 
TaRV
�� 
SyTo
�� 
SySr
�� .TrAnSyncnull���     FilV
�� .coreclosnull���     obj �� �� |*�-�[�,\Z�81�k/E�O*�-�[�,\Z�81E�O*���*6� �, K*a �l O*a ,a a l O*a ,a a l O*a ,a *a ,a �� O*a ,j UUascr  ��ޭ